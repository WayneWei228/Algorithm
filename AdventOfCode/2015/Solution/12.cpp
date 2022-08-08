#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[27278];

struct Json {
    virtual int Visit(bool withoutRed) const = 0;
    virtual bool IsRed() const { return false; }
};

unique_ptr<Json> ParseJson(const string& s, int& start);

struct JsonString : public Json {
    string Data;

    bool Parse(const string& s, int& start) {
        if (s[start] != '"') return false;
        if (s[start] == '"') ++start;
        int size = 0;
        sscanf(s.c_str() + start, "%[^\"]%n", Buffer, &size);
        Data = Buffer;
        start += size;
        if (s[start] == '"') ++start;
        return true;
    }

    int Visit(bool withoutRed) const { return 0; }
    bool IsRed() const { return Data == "red"; }
};

struct JsonNumber : public Json {
    int Data;

    bool Parse(const string& s, int& start) {
        int size = 0;
        sscanf(s.c_str() + start, "%d%n", &Data, &size);
        start += size;
        return true;
    }

    int Visit(bool withoutRed) const { return Data; }
};

struct JsonObject : public Json {
    unordered_map<string, unique_ptr<Json>> Data;

    bool Parse(const string& s, int& start) {
        if (s[start] != '{') return false;
        if (s[start] == '{') ++start;
        while (s[start] != '}') {
            JsonString jsonS;
            jsonS.Parse(s, start);
            if (s[start] == ':') ++start;
            Data[jsonS.Data] = ParseJson(s, start);
            if (s[start] == ',') ++start;
        }
        if (s[start] == '}') ++start;
        return true;
    }

    int Visit(bool withoutRed) const {
        if (withoutRed) {
            for (const auto& i : Data) {
                if (i.second->IsRed()) return 0;
            }
        }
        int answer = 0;
        for (const auto& i : Data) {
            answer += i.second->Visit(withoutRed);
        }
        return answer;
    }
};

struct JsonArray : public Json {
    vector<unique_ptr<Json>> Data;

    bool Parse(const string& s, int& start) {
        if (s[start] != '[') return false;
        if (s[start] == '[') ++start;
        while (s[start] != ']') {
            Data.emplace_back(ParseJson(s, start));
            if (s[start] == ',') ++start;
        }
        if (s[start] == ']') ++start;
        return true;
    }

    int Visit(bool withoutRed) const {
        int answer = 0;
        for (const auto& i : Data) {
            answer += i->Visit(withoutRed);
        }
        return answer;
    }
};

unique_ptr<Json> ParseJson(const string& s, int& start) {
    auto jsonO = make_unique<JsonObject>();
    if (jsonO->Parse(s, start)) return jsonO;
    auto jsonA = make_unique<JsonArray>();
    if (jsonA->Parse(s, start)) return jsonA;
    auto jsonS = make_unique<JsonString>();
    if (jsonS->Parse(s, start)) return jsonS;
    auto jsonN = make_unique<JsonNumber>();
    if (jsonN->Parse(s, start)) return jsonN;
    return jsonO;
}

struct Solution {
    unique_ptr<Json> Input;

    void Solve() {
        scanf("%s", Buffer);
        int start = 0;
        Input = ParseJson(Buffer, start);
        printf("%d\n", Input->Visit(false));
        printf("%d\n", Input->Visit(true));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
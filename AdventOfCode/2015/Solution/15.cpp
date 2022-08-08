#include <cstdio>
#include <string>
#include <vector>
using namespace std;

// Sprinkles: capacity 5, durability -1, flavor 0, texture 0, calories 5

struct Ingredient {
    int Capacity, Durability, Flavor, Texture, Calories;

    Ingredient(const string& input) {
        sscanf(input.c_str(),
               "%*s capacity %d, durability %d, flavor %d, "
               "texture %d, calories %d",
               &Capacity, &Durability, &Flavor, &Texture, &Calories);
    }
};

char Buffer[80];

const int Room = 100;

struct Solution {
    vector<Ingredient> Input;
    vector<int> Amount;
    int TotalCalories, MaxScore;

    void Put(int no, int roomLeft) {
        if (no == Input.size() - 1) {
            Amount[no] = roomLeft;
            int capacity = 0, durability = 0, flavor = 0, texture = 0,
                calories = 0;
            for (int i = 0; i < Input.size(); ++i) {
                capacity += Input[i].Capacity * Amount[i];
                durability += Input[i].Durability * Amount[i];
                flavor += Input[i].Flavor * Amount[i];
                texture += Input[i].Texture * Amount[i];
                calories += Input[i].Calories * Amount[i];
            }
            if (TotalCalories == -1 || TotalCalories == calories) { //  -1 为第一题， 500 为第二题
                if (capacity < 0) capacity = 0;
                if (durability < 0) durability = 0;
                if (flavor < 0) flavor = 0;
                if (texture < 0) texture = 0;
                int score = capacity * durability * flavor * texture;
                if (MaxScore < score) MaxScore = score;
            }
            return;
        }
        for (int i = 0; i <= roomLeft; ++i) {
            Amount[no] = i;
            Put(no + 1, roomLeft - i);
        }
    }

    void Solve() {
        while (true) {
            if (scanf("%[^\n]\n", Buffer) < 1) break;
            Input.emplace_back(Buffer);
        }
        Amount.resize(Input.size());
        TotalCalories = -1;
        MaxScore = 0;
        Put(0, Room);
        printf("%d\n", MaxScore);
        TotalCalories = 500;
        MaxScore = 0;
        Put(0, Room);
        printf("%d\n", MaxScore);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
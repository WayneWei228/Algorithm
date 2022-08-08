//USACO 2016 December Contest, Silver Problem 2. Cities and States
/*
 In this problem, we have pairs of cities and states. We want to count the number of "special pairs", where the first two letters of the city in one pair is the state in the other pair and the two cities are in different states.

 Because there are up to 2⋅105 cities to consider, we cannot iterate over all possible pairings of cities.

 Note that we can reduce a given city/state pair into a four letter string, where the first two letters are the first two letters of the city and the last two letters are the state code. If two cities form a special pair, then it must be the case that the first two letters swap with the last two letters. Also, the first two letters and last two letters cannot be identical. We can store the number of times a given four-letter string appears in a map for an O(N) algorithm.
 */
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    map<string,long> codeList;
    map<string,long>::iterator it;
    string city,state;
    cin>>n;
    string key;
    for(int i=0;i<n;i++)
    {
        cin>>city>>state;
        //printf("%s\n",city.substr(0, 2).c_str());
        if(city.substr(0, 2).compare(state)!=0)
        {
            
            key = city.substr(0, 2) + state;
            if(codeList.find(key)==codeList.end()){
                codeList[key]=1;
            }
            else{
                codeList[key]+=1;
            }
        }
        	
    }
    
    
    
    /*for(it=codeList.begin();it!=codeList.end();it++)
    {
        printf("%s %ld\n",it->first.c_str(),it->second);
    }*/
    it=codeList.begin();
    long ret = 0;
    while(it!=codeList.end())
    {
        string otherKey = it->first.substr(2) + it->first.substr(0, 2);
        //printf("%s\n",otherKey.c_str());
        //if(codeList.find(otherKey)!=codeList.end()&&it->first.substr(2)！=otherKey.substr(2)) {
            //ret += codeList[key] * codeList[otherKey];
        if(codeList.find(otherKey)!=codeList.end()){
            ret += codeList[it->first] * codeList[otherKey];
        }
        it++;
        
        
    }
    printf("%ld",ret/2);
    
}


/*
 FLAAL FL
 FLBBL FL
 FL    FL
 
 
 FLAAL AL
 FLBBL AL
 ALCCL FL
 
 FLAL   2
 ALFL   1
 
 
 */

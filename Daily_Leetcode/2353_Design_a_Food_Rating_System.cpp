https://leetcode.com/problems/design-a-food-rating-system/description/?envType=daily-question&envId=2025-09-17
struct Compare{
    bool operator()(pair<string, int> p1, pair<string, int> p2){
        if(p1.second == p2.second) return p1.first > p2.first; //smallest string
        return p1.second < p2.second; //highest rated
    }
};

// [[["emgqdbo","jmvfxjohq","qnvseohnoe","yhptazyko","ocqmvmwjq"],
//     ["snaxol","snaxol","snaxol","fajbervsj","fajbervsj"],  
    // [14,9,11,6,5]],

// ["qnvseohnoe",11],["fajbervsj"],["emgqdbo",3],["jmvfxjohq",9],["emgqdbo",14],["fajbervsj"],["snaxol"]]

class FoodRatings {
public:
    // similar to give max value every time
    // we will keep on adding new values, but here it is foods

    // priority queue (max heap ) with pair(foood[i], cuisines[i], ratings[i])
    // given cuisine value
    // max heap gives us the max value 
    // return the max cusines values, if there is a tie return the lexicographically smaller name(food)

    // unordered_map<string, priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>> cuisinesMap;
    
    //set by deafult returns smaller values first (orders in asc order)
    unordered_map<string, set<pair<int, string>>> cuisinesMap;
    unordered_map<string, string> foodCuisineTypes;
    unordered_map<string, int> foodRatings;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            foodRatings[foods[i]] = ratings[i];
            foodCuisineTypes[foods[i]] = cuisines[i];
            if(cuisinesMap.find(cuisines[i])==cuisinesMap.end()){
                // priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> max_heap;
                set<pair<int, string>> cus_set;
                cus_set.insert({-ratings[i], foods[i]});
                cuisinesMap[cuisines[i]] = cus_set;
            }
            else{
                cuisinesMap[cuisines[i]].insert({-ratings[i], foods[i]});
            }
        }
    }
    
    void changeRating(string food, int newRating) {
        // if(foodRatings.find(food)!=foodRatings.end()){
        //     cuisinesMap[foodCuisineTypes[food]].erase({food, foodRatings[food]});
        // }

        // vector<pair<string, int>> tmpQ;

        // while(!cuisinesMap[foodCuisineTypes[food]].empty()){
        //     auto [foodm, pr] = cuisinesMap[foodCuisineTypes[food]].top(); cuisinesMap[foodCuisineTypes[food]].pop();
        //     if(foodm==food) break;
        //     tmpQ.push_back({foodm, pr});
        // }

        // for(auto p : tmpQ){
        //     cuisinesMap[foodCuisineTypes[food]].push(p);
        // }
        // auto it  = cuisinesMap[foodCuisineTypes[food]].find({food,foodRatings[food]});

        cuisinesMap[foodCuisineTypes[food]].erase({-foodRatings[food], food});

        cuisinesMap[foodCuisineTypes[food]].insert({-newRating, food});
        foodRatings[food] = newRating;
    }
    
    string highestRated(string cuisine) {

        // cout << cuisinesMap[cuisine].size() << " : " << cuisinesMap[cuisine].top().second << endl;

        return cuisinesMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
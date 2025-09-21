struct Entry {
    int price, shop, movie;
    bool operator<(const Entry& other) const {
        if (price != other.price) return price < other.price;
        if (shop != other.shop) return shop < other.shop;
        return movie < other.movie;
    }
};

class MovieRentingSystem {
    map<int, set<pair<int, int>>> avail;
    map<pair<int, int>, int> price_map;
    set<Entry> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            avail[movie].insert({price, shop});
            price_map[{shop, movie}] = price;
        }
    }
    vector<int> search(int movie) {
        vector<int> res;
        auto& s = avail[movie];
        for (auto it = s.begin(); it != s.end() && res.size() < 5; ++it)
            res.push_back(it->second);
        return res;
    }
    void rent(int shop, int movie) {
        int price = price_map[{shop, movie}];
        avail[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    void drop(int shop, int movie) {
        int price = price_map[{shop, movie}];
        rented.erase({price, shop, movie});
        avail[movie].insert({price, shop});
    }
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && res.size() < 5; ++it)
            res.push_back({it->shop, it->movie});
        return res;
    }
};
/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
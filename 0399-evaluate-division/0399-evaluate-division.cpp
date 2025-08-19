class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> g;
                for (int i = 0; i < equations.size(); ++i) {
                            string a = equations[i][0], b = equations[i][1];
                                        double v = values[i];
                                                    g[a].push_back({b, v});
                                                                g[b].push_back({a, 1.0 / v});
                                                                        }

                                                                                auto eval = [&](const string& src, const string& dst) -> double {
                                                                                            if (!g.count(src) || !g.count(dst)) return -1.0;
                                                                                                        if (src == dst) return 1.0;
                                                                                                                    unordered_set<string> vis;
                                                                                                                                queue<pair<string,double>> q;
                                                                                                                                            q.push({src, 1.0});
                                                                                                                                                        vis.insert(src);
                                                                                                                                                                    while (!q.empty()) {
                                                                                                                                                                                    auto [u, w] = q.front(); q.pop();
                                                                                                                                                                                                    if (u == dst) return w;
                                                                                                                                                                                                                    for (auto& [v, k] : g[u]) {
                                                                                                                                                                                                                                        if (vis.count(v)) continue;
                                                                                                                                                                                                                                                            vis.insert(v);
                                                                                                                                                                                                                                                                                q.push({v, w * k});
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                        return -1.0;
                                                                                                                                                                                                                                                                                                                                };

                                                                                                                                                                                                                                                                                                                                        vector<double> ans;
                                                                                                                                                                                                                                                                                                                                                ans.reserve(queries.size());
                                                                                                                                                                                                                                                                                                                                                        for (auto& q : queries) ans.push_back(eval(q[0], q[1]));
                                                                                                                                                                                                                                                                                                                                                                return ans;
    }
};
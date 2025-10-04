class Solution {
    public:
        int maxArea(vector<int>& height) {
  int left = 0, right = height.size() - 1, ans = 0;
 while (left < right) {
int h = min(height[left], height[right]);
  ans = max(ans, h * (right - left));
    if (height[left] < height[right])
 ++left;
 else
  --right;
  }
return ans;
 }
      };


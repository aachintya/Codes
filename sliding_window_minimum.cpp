#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    stack<pair<int, int>> stack1, stack2;
    int o = 0;

    for (int i = 0; i < n; ++i) {
        int e = stack1.empty() ? x : (stack1.top().second | x);
        stack1.push({x, e});
        x = (1LL * a * x + b) % c;

        if (i >= k - 1) {
            if (stack1.empty()) {
                o ^= stack2.top().second;
            } else if (stack2.empty()) {
                o ^= stack1.top().second;
            } else {
                o ^= (stack1.top().second | stack2.top().second);
            }

            if (stack2.empty()) {
                while (!stack1.empty()) {
                    int elem = stack1.top().first;
                    int mini = elem;
                    stack1.pop();
                    if (!stack2.empty()) {
                        mini |= stack2.top().second;
                    }
                    stack2.push({elem, mini});
                }
            }

            stack2.pop();
        }
    }

    cout << o << '\n';
    return 0;
}

#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>

const int INF = 100000;

using namespace std;

void GetLinkStart(int start, vector<vector<int>> &vv, int n, vector<int> &waitingPoints, vector<int> &visited) {
    for (int j = 0; j < n; ++j)
        if (vv[start][j] > 0) {
            bool flag = true;
            for (int i = 0; i < visited.size(); ++i) {
                if (visited[i] == j) flag = false;
            }
            if (flag) waitingPoints.push_back(j);
        }
}

void DeykstraAlgorithm(vector<vector<int>> vv, int n, int s, int f) {
    vector<int> visited = {s};
    vector<int> length(n, INF);
    length[s] = 0;
    int start = s;
    while (start != -1) {
        vector<int> waitingPoints;
        GetLinkStart(start, vv, n, waitingPoints, visited);
        for (int j = 0; j < waitingPoints.size(); ++j) {
            length[waitingPoints[j]] = min(length[start] + vv[start][waitingPoints[j]], length[waitingPoints[j]]);
        }
        if (waitingPoints.size() == 0) {
            start = -1;
            break;
        } else {
            int minPoint, valueMinPoint = INF;
            for (int j = 0; j < n; ++j) {
                if (length[j] < valueMinPoint) {
                    bool flag = true;
                    for (int i = 0; i < visited.size(); ++i) {
                        if (visited[i] == j) flag = false;
                    }
                    if (flag) {
                        valueMinPoint = length[j];
                        minPoint = j;
                    }
                }
            }
            if (valueMinPoint != INF) {
                visited.push_back(minPoint);
                start = minPoint;
            } else start = -1;
        }
        waitingPoints.clear();

    }
    cout << length[f] << endl;
}

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    s -= 1;
    f -= 1;
    vector<vector<int>> vv(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> vv[i][j];
    DeykstraAlgorithm(vv, n, s, f);
    return 0;
}

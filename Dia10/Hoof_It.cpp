#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <fstream>

using namespace std;

// Direction vectors for up, right, down, left movements
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

class HikingTrails {
private:
    vector<vector<int>> grid;
    int rows, cols;
    
    bool isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    
    // Part 1: Count reachable nines
    int countReachableNines(int startX, int startY) {
        set<pair<int, int>> reachableNines;
        queue<pair<pair<int, int>, int>> q;
        set<pair<pair<int, int>, int>> visited;
        
        q.push({{startX, startY}, 0});
        visited.insert({{startX, startY}, 0});
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int x = current.first.first;
            int y = current.first.second;
            int height = current.second;
            
            if (grid[x][y] == 9) {
                reachableNines.insert({x, y});
                continue;
            }
            
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if (isValid(newX, newY)) {
                    if (grid[newX][newY] == height + 1) {
                        pair<pair<int, int>, int> newState = {{newX, newY}, height + 1};
                        if (visited.find(newState) == visited.end()) {
                            visited.insert(newState);
                            q.push(newState);
                        }
                    }
                }
            }
        }
        
        return reachableNines.size();
    }
    
    // Part 2: Count distinct paths using DFS with memoization
    long long countDistinctPaths(int x, int y, int height, 
                               map<pair<pair<int, int>, int>, long long>& memo,
                               vector<vector<bool>>& visited) {
        // Base case: reached height 9
        if (grid[x][y] == 9) {
            return 1;
        }
        
        // Check memoization cache
        pair<pair<int, int>, int> state = {{x, y}, height};
        if (memo.find(state) != memo.end()) {
            return memo[state];
        }
        
        long long paths = 0;
        visited[x][y] = true;
        
        // Try all four directions
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isValid(newX, newY) && !visited[newX][newY] && 
                grid[newX][newY] == height + 1) {
                paths += countDistinctPaths(newX, newY, height + 1, memo, visited);
            }
        }
        
        visited[x][y] = false;
        memo[state] = paths;
        return paths;
    }
    
public:
    HikingTrails(const string& filename) {
        loadFromFile(filename);
    }
    
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Unable to open file: " + filename);
        }
        
        string line;
        vector<string> input;
        
        while (getline(file, line)) {
            if (!line.empty()) {
                input.push_back(line);
            }
        }
        
        rows = input.size();
        if (rows == 0) {
            throw runtime_error("Empty file");
        }
        cols = input[0].length();
        
        grid.resize(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            if (input[i].length() != cols) {
                throw runtime_error("Inconsistent line length in input file");
            }
            for (int j = 0; j < cols; j++) {
                if (!isdigit(input[i][j])) {
                    throw runtime_error("Invalid character in input file");
                }
                grid[i][j] = input[i][j] - '0';
            }
        }
        
        file.close();
    }
    
    // Part 1: Calculate total score (reachable nines)
    int calculateTotalScore() {
        int totalScore = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    int score = countReachableNines(i, j);
                    totalScore += score;
                    cout << "Trailhead at (" << i << "," << j << ") has score: " << score << endl;
                }
            }
        }
        
        return totalScore;
    }
    
    // Part 2: Calculate total rating (distinct paths)
    long long calculateTotalRating() {
        long long totalRating = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    map<pair<pair<int, int>, int>, long long> memo;
                    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                    long long rating = countDistinctPaths(i, j, 0, memo, visited);
                    totalRating += rating;
                    cout << "Trailhead at (" << i << "," << j << ") has rating: " << rating << endl;
                }
            }
        }
        
        return totalRating;
    }
    
    void printGrid() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }
    
    try {
        HikingTrails solver(argv[1]);
        
        cout << "Loaded map:" << endl;
        solver.printGrid();
        cout << endl;
        
        int score = solver.calculateTotalScore();
        cout << "Total score (Part 1): " << score << endl;
        
        long long rating = solver.calculateTotalRating();
        cout << "Total rating (Part 2): " << rating << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
class SubrectangleQueries {
public:
    vector<vector<int>> v,rect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        v.push_back({row1,col1,row2,col2,newValue});
    }
    
    int getValue(int row, int col) {
        int value=rect[row][col];
        for(auto arr: v){
            if(row>=arr[0]and col>=arr[1] and row<=arr[2] and col<=arr[3])
                value=arr[4];
        }
        return value;
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
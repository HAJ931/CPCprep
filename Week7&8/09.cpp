class Solution {
private:
    void canVisitAllRoomsUtil(int room, int& num, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[room] = true;
        ++num;
        for(auto r: rooms[room]){
            if(!visited[r])
                canVisitAllRoomsUtil(r, num, rooms, visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num = 0;
        vector<bool> visited(rooms.size(), false);
        canVisitAllRoomsUtil(0, num, rooms, visited);
        /*for(auto room: visited){
            if(!room)
                return false;
        }*/
        if(num < rooms.size())
                return false;
        return true;
    }
};

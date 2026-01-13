#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<double,double> calculateForAllSquares(const vector<vector<int>>& squares, double y_line){
        // cout << "y line : " << y_line << endl;
        double up_area = 0, down_area = 0;

        for(int i=0; i<squares.size(); i++){
            // vector<int> square = squares[i];
            // int x = square[0], 
            int y = squares[i][1], l = squares[i][2];
            double y_up = y+l, y_down = y;

            if(y_line >= y_up){
                // bottom area
                down_area += ((double)l*l);
            }
            else if(y_line <= y_down){
                // up area
                up_area += ((double)l*l);
            }
            else{
                double y_side = (y_up - y_line);
                up_area += y_side * l;

                y_side = (y_line - y_down);
                down_area += y_side * l;
            }
        }
        // cout << "up : " << up_area << " down : " << down_area << endl;
        return {up_area, down_area};
    }

    double separateSquares(vector<vector<int>>& squares) {
        // binary search on y value

        double min_y = 1e9, max_y = -1e9;

        for(int i=0; i<squares.size(); i++){
            min_y = min(min_y, (double)squares[i][1]);
            max_y = max(max_y, (double)squares[i][1]+squares[i][2]);
        }

        double y_line = max_y - (max_y - min_y)/2;

        auto areas = calculateForAllSquares(squares, y_line);
        double up_area = areas.first, down_area = areas.second;

        const double EPS = 1e-6;

        while(max_y - min_y > EPS){
            // cout << "min_y : " << min_y << " ==  max_y : " << max_y <<  endl;
            // if(min_y < max_y) cout << "yes" << endl;
            // else cout << "no" << endl;
            // cout << up_area << " : " << down_area << endl;
            
            y_line = max_y - (max_y - min_y)/2;
            areas = calculateForAllSquares(squares, y_line);
            up_area = areas.first;
            down_area = areas.second;

            if(up_area <= down_area){
                // down area is more than up area
                // decrease the high end
                max_y = y_line;
            }
            else if(up_area > down_area){
                // up area is more than down area
                // increase the low end
                min_y = y_line;
            }
            // else{
            //     return y_line;
            // }
        }


        return y_line;
        // calculate mid value and then area above the line and area below the line
        // How to calculate the area above the line
        // y_line = something like mid line from max y --- min y
            // calculate for all squares (overlapping)
                // (x, y, l) 
                //  y_up = (y+l), y_down = y
                // if y_line > y_up 
                //      --> total area for bottom side
                // else if y_line < y_down
                //      --> total area for up side
                // else{
                //      --> calculate up side with y_side = (y_up - y_line)
                //          --> y_side * x
                //      --> calculate down side with y_side = (y_line - y_down)
                //          --> y_side * x
                // }
        // 
    }
};
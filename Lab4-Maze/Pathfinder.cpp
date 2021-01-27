#include "Pathfinder.h"

string Pathfinder::toString() const
{
    stringstream ss;
    for(int layer = 0; layer < LAYER_SIZE; layer++){
	    for(int row = 0; row < ROW_SIZE; row++) {
	        for(int col = 0; col < COL_SIZE; col++) {
	            ss << maze_grid[layer][row][col];
	            if (col < 4){
	                ss << " ";
	            }
	        }
	        ss << endl;
	    }
	    if (layer < 4){
	        ss << endl;
	    }
    }
    return ss.str();
}

void Pathfinder::createRandomMaze()
{
	for(int layer = 0; layer < LAYER_SIZE; layer++){
	    for(int row = 0; row < ROW_SIZE; row++) {
	        for(int col = 0; col < COL_SIZE; col++) {
			       maze_grid[layer][row][col] = rand() % 2;
			    }
	        }
	    }
    maze_grid[0][0][0] = 1;
	maze_grid[4][4][4] = 1;
   }


bool Pathfinder::importMaze(string file_name)
{
//cout << "importMaze from "<<file_name<<endl;
	
	ifstream file (file_name.c_str());
	char token;
	int counter = 0;
	if(file.is_open()){
	    while (file >> token){
	        if ( (token == '0') || (token == '1') ){
	            counter++;
	        }
	        else {
	            //cout << "Invalid file format" << endl;
	            return false;
	        }
	    }
	    if (counter != 125){
	        //cout << "Invalid file format" << endl;
	        return false;
	    }
	    file.close();
	}
	else{
	    //cout << "File not found" << endl;
	    return false;
	}
	
    file.open(file_name);
	if (file.is_open()) {
		string line;
		for(int layer = 0; layer < LAYER_SIZE; layer++){
    		for(int row = 0; row < ROW_SIZE; row++) {
    			getline(file, line);
    			stringstream ss(line);
    			for(int col = 0; col < COL_SIZE; col++) {
    				int value;
    				ss >> value;
    				if ( (layer == 0 && row == 0 && col == 0 && value == 0) ||
    				     (layer == 4 && row == 4 && col == 4 && value == 0)){
    				    //cout << "Invalid file format" << endl;
    				    return false;
    				}
				    //cout << "["<<row<<"]["<<col<<"]["<<layer<<"]="<<value<<endl;
				    maze_grid[layer][row][col] = value;
    			}
    			ss.str("");
    		}
    		getline(file,line);
		}
		file.close();
	}
//cout << "Input maze from " << file_name << ": " << endl << this->toString();
    return(true);
}

vector<string> Pathfinder::solveMaze()
{
	vector<string> empty;
	solution.clear();
	copyMaze(maze_grid, grid_copy);
	if(find_maze_path(grid_copy, 0, 0, 0)){
		cout << "Returning solution" << endl;
		return solution;
	}
	else{
		return empty;
	}
}


bool Pathfinder::find_maze_path(int grid[ROW_SIZE][COL_SIZE][LAYER_SIZE], int x, int y, int z){
	
//cout << "find_maze_path ["<<r<<"]["<<c<<"]["<<l<<"]"<<endl;
//cout << this->toString();
	
	ostringstream step;
	step.str("");
    step << "(" << x << ", " << y << ", " << z << ")";
	if (x < 0 || y < 0 || z < 0 || x >= ROW_SIZE || y >= COL_SIZE || z >= LAYER_SIZE){
		return false;      // Cell is out of bounds.
	}
	else if (grid[z][y][x] != BACKGROUND){
//cout << "Attempted to go through blocked, walled, or previously visited cell" << endl;
//cout << "Coordinates: " << r << " " << c << " " << l << endl;
		return false;      // Cell is on barrier or dead end.
	}
	else if ( (x == ROW_SIZE - 1) && (y == COL_SIZE - 1) && (z == LAYER_SIZE - 1) ) {
		grid[z][y][x] = PATH;         // Cell is on path
		solution.insert(solution.begin(), step.str());
		return true;                  // and is maze exit.
	}
	else {
	// Recursive case.
	// Attempt to find a path from each neighbor.
	// Tentatively mark cell as on path.
		grid[z][y][x] = PATH;
		if (find_maze_path(grid, x - 1, y, z) // Up
		 || find_maze_path(grid, x + 1, y, z) // Down
		 || find_maze_path(grid, x, y - 1, z) // Left
		 || find_maze_path(grid, x, y + 1, z) // Right
		 || find_maze_path(grid, x, y, z - 1) // Up layer
		 || find_maze_path(grid, x, y, z + 1) ) { //Down Layer
		 	
			solution.insert(solution.begin(), step.str());
			return true;
		}
		else {
			grid[z][y][x] = TEMPORARY;  // Dead end.
			return false;
		}
	}
}

void Pathfinder::copyMaze(int maze_grid[ROW_SIZE][COL_SIZE][LAYER_SIZE], int grid_copy[ROW_SIZE][COL_SIZE][LAYER_SIZE]){
	for(int layer = 0; layer < LAYER_SIZE; layer++){
        for(int row = 0; row < ROW_SIZE; row++) {
	        for(int col = 0; col < COL_SIZE; col++) {
	        	grid_copy[layer][row][col] = maze_grid[layer][row][col];
	        }
        }
	}
}
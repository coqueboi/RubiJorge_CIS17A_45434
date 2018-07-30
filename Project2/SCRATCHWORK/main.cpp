//Generate Cruiser ship3
    do{
        //Get the spawn coords with every loop in case they are modified or reset
        ship3.setCoords();
        coords = ship3.getCoords();
        length = ship3.getLength();
        //Reset temporary variables for each ship loop
        sizeTemp = 0, xVal = 0, yVal = 0, count = 0;
        
        //Attempt horizontal generation
        if(ship3.getOrient() == 0 ){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[1] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[1] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int x = 0; x < length; x++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal][xVal + x] == '1'){
                    //Hold the position generation was at in order to undo
                    count = x;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal][xVal + x] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal][xVal + x] = '1';
                    
                    //Store placement coordinate
                    ship3.place[x + x] = yVal;
                    ship3.place[x + x + 1] = xVal + x;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int x = coords[1]; x < coords[1] + count; x++){
                    board[yVal][x] = '+';
                    
                    //Undo storing of placement coordinate
                    ship3.place[x + x] = 0;
                    ship3.place[x + x + 1] = 0;
                }
            }
        }
        //Attempt vertical generation
        else if(ship3.getOrient() == 1){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[0] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[0] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int y = 0; y < length; y++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal + y][xVal] == '1'){
                    //Hold the position generation was at in order to undo
                    count = y;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal + y][xVal] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal + y][xVal] = '1';
                    
                    //Store placement coordinate
                    ship3.place[y + y] = yVal + y;
                  
                    ship3.place[y + y + 1] = xVal;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int y = coords[0]; y < coords[0] + count; y++){
                    board[y][xVal] = '+';
                    //Undo storing of placement coordinate
                    ship3.place[y + y] = 0;
                    ship3.place[y + y + 1] = 0;
                }
            }
        }
        else{
            cout << "An error occurred" << endl;
            exit(EXIT_FAILURE);
        }
    }while(!gen);
    //Debugging
    //    for(int i = 0; i < length; i++){
    //        cout << ship3.place[i + i] << ship3.place[i + i + 1] << endl;
    //    }
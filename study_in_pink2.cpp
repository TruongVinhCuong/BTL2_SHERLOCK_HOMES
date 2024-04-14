#include "study_in_pink2.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
class TestStudyInPink;
//3.1
MapElement::MapElement(ElementType in_type){
        type=in_type;
    }
    
ElementType MapElement::getType() const{
    return this->type;
}

FakeWall::FakeWall(int in_req_exp) : MapElement(FAKE_WALL){
        req_exp=in_req_exp;
    }

int FakeWall::getReqExp() const{
    return this->req_exp;
}
//3.2
Map::Map(int num_rows, int num_cols, int num_walls, Position * array_walls, int num_fake_walls, Position * array_fake_walls) : num_rows(num_rows), num_cols(num_cols){
    map = new MapElement ** [num_rows];
    for(int i=0; i<num_rows; i++){
        map[i] = new MapElement * [num_cols];
    }
}
Map::~Map(){
    for(int i=0; i<num_rows; i++){
        for (int j=0; j<num_cols; j++){
            delete [] map[i][j];
        }
        delete [] map[i];
    }
    delete [] map;
}


//3.3
Position::Position(const string & str_pos){
        string a=str_pos.substr(1, str_pos.find(",") - 1);
        string b=str_pos.substr(str_pos.find(",") + 1, str_pos.find(")") - 1);
        stringstream str2num1(a);
        int x=0;
        str2num1 >> x;
        stringstream str2num2(b);
        int y=0;
        str2num2 >> y;
        this->r=x;
        this->c=y;
    }

int Position::getRow() const{
        return this->r;
    }
int Position::getCol() const{
        return this->c;
    }
void Position::setRow(int r){
        this->r=r;
    }
void Position::setCol(int c){
        this->c=c;
    }

string Position::str() const{
        string thongtin="(" + to_string(r) + "," + to_string(c) + ")";
        return thongtin;
    }
//3.4
MovingObject::MovingObject(int index, const Position pos, Map * map, const string & name=""){
        this->index=index;
        this->pos=pos;
        this->map=map;
        this->name=name;
    }
//3.5
//3.6
//3.7
//3.8
//3.9
Configuration::Configuration(const string & filepath){
    string arr[30];
    ifstream file1;
    file1.open(filepath);
    while(!file1.eof()){
        for(int i=0; i<30; i++){
            file1 >> arr[i];
        }
    }
    for(int i=0; i<30; i++){
        cout << arr[i] << endl;
    }
    file1.close();
    for(int i=1; i<30; i+=2){
        if(arr[i].find("MAP_NUM_ROWS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            map_num_rows=x;
        } else if(arr[i].find("MAP_NUM_COLS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            map_num_cols=x;
        } else if(arr[i].find("MAX_NUM_MOVING_OBJECTS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            max_num_moving_objects=x;
        } else if(arr[i].find("ARRAY_WALLS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            int count=0;
            for(int i=0; i<a.size(); i++){
                if(a[i]=='('){
                    ++count;
                }
            }
            num_walls=count;
        } else if(arr[i].find("ARRAY_FAKE_WALLS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            int count=0;
            for(int i=0; i<a.size(); i++){
                if(a[i]=='('){
                    ++count;
                }
            }
            num_fake_walls=count;
        } else if(arr[i].find("SHERLOCK_MOVING_RULE") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            sherlock_moving_rule=a;
        } else if(arr[i].find("SHERLOCK_INIT_POS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
        } else if(arr[i].find("SHERLOCK_INIT_HP") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            sherlock_init_hp=x;
        } else if(arr[i].find("SHERLOCK_INIT_EXP") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            sherlock_init_exp=x;
        } else if(arr[i].find("WATSON_MOVING_RULE") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            watson_moving_rule=a;
        } else if(arr[i].find("WATSON_INIT_POS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
        } else if(arr[i].find("WATSON_INIT_HP") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            watson_init_hp=x;
        } else if(arr[i].find("WATSON_INIT_EXP") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            watson_init_exp=x;
        } else if(arr[i].find("CRIMINAL_INIT_POS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
        } else if(arr[i].find("NUM_STEPS") != string::npos){
            string a=arr[i].substr(arr[i].find("="));
            stringstream str2num(a);
            int x=0;
            str2num >> x;
            num_steps=x;
        }
    }
}
//3.10
//3.11
//3.12
//3.13
//3.14

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
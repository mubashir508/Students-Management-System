
#ifndef PROJECT_NEW_CSV_H
#define PROJECT_NEW_CSV_H

#include <vector>
#include <sstream>

std::vector<std::string> csv_read_row(std::istream &in, char delimiter){
    std::stringstream ss;
    bool inquotes = false;
    std::vector<std::string> row;//relying on RVO
    while(in.good())
    {
        char c = in.get();
        if (!inquotes && c=='"') //beginquotechar
        {
            inquotes=true;
        }
        else if (inquotes && c=='"') //quotechar
        {
            if ( in.peek() == '"')//2 consecutive quotes resolve to 1
            {
                ss << (char)in.get();
            }
            else //endquotechar
            {
                inquotes=false;
            }
        }
        else if (!inquotes && c==delimiter) //end of field
        {
            row.push_back( ss.str() );
            ss.str("");
        }
        else if (!inquotes && (c=='\r' || c=='\n') )
        {
            if(in.peek()=='\n') { in.get(); }
            row.push_back( ss.str() );
            return row;
        }
        else
        {
            ss << c;
        }
    }
}

#endif //PROJECT_NEW_CSV_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<vector>
#include <sstream>
using namespace std;

struct grid
{
    map<int, vector<int>> cellList;
    int info[4];

};

class annealing
{
public:
    grid anngrid;
    
    void netl(string filename)
    {
        ifstream netlist;
        map<int, vector<int>> cellList;
        int cells, connections, rows, columns;
        netlist.open(filename);

        netlist >> cells;
        netlist >> connections;
        netlist >> rows;
        netlist >> columns;
        cout << cells << "\t" << connections << "\t" << rows << "\t" << columns << "\n";
        int numberofcon;
        vector<int> netconc;
        for (int i = 0; i < connections; i++)
        {

            //getline(netList,test);
            netlist >> numberofcon;
            //cout << "\n" << numberofcon;
            netconc.resize(numberofcon);
            for (int j = 0; j < numberofcon; j++)
            {
                netlist >> netconc[j];
            }
            cellList.insert(pair<int, vector<int>>(numberofcon, netconc));
        }
        grid plan;
        plan.cellList = cellList;
        plan.info[0] = cells;
        plan.info[1] = connections;
        plan.info[2] = rows;
        plan.info[3] = columns;

        netlist.close();

    }
    void anneal()
    {
        int x = anngrid.info[2];
        int y = anngrid.info[3];
        int z = anngrid.info[0];
        vector<vector<int>> sqgrid;
        
        int minX=x , minY=y;
        int maxX=0 , maxY=0;
        bool rejected = false;
        /*for (int i = 0; i < x; i++) {

            // Declare a memory block
            // of size n
            sqgrid[i] = new int[y];
        }*/
        
        //Declaring a 2D-vector of size: x * y
        sqgrid.resize(x);
        
        for(int i = 0 ; i < x ; i++)
            sqgrid[i].resize(y);
        
        //Filling the 2D-vector with empty cells
        for(int i = 0 ; i < x ; i++)
        {
               for(int j = 0 ; j < y ; j++)
               {
                   sqgrid[i][j]= -1;
               }
        }
        
        //Initial Placement
        srand((unsigned)time(0));
        for (int i = 1; i < z+1; i++)
           {
               if(rejected)
                   i--;
               
               int rn1 = (rand() % x);
               int rn2 = (rand() % y);
               
               if (sqgrid[rn1][rn2] == -1)
                   {
                       sqgrid[rn1][rn2]= i;
                       
                       if(rn1>maxX)
                           maxX=rn1;
                       
                       if(rn2>maxY)
                           maxY=rn2;
                       
                       if(rn1<minX)
                           minX=rn1;
                       
                       if(rn2<minY)
                           minY=rn2;
                       
                       rejected=false;
                   }
               else
                   rejected=true;
           }

        int rn1 = (rand() % x) ;
        int rn2 = (rand() % y) ;
        int rn3 = (rand() % x);
        int rn4 = (rand() % y);
        
        while (sqgrid[rn1][rn2] == -1)
        {
         rn1 = (rand() % x);
         rn2 = (rand() % y);
        
        }
        while (sqgrid[rn3][rn4] == -1)
        {
            rn3 = (rand() % x);
            rn4 = (rand() % y);
        }
        swap(rn1, rn2, sqgrid[rn1][rn2], rn3, rn4, sqgrid[rn3][rn4]);

        //choosing random swap

    }
    void swap(int& x1, int& y1, int& val1, int& x2, int& y2, int& val2)
    {
        int xtmp, ytmp, valtmp;
        xtmp = x1;
        ytmp = y1;
        valtmp = val1;
        x1 = x2;
        y1 = y2;
        val1 = val2;
        x2 = xtmp;
        y2 = ytmp;
        val2 = valtmp;
    }

};



void netl(string filename)
{
    ifstream netlist;
    map<int, vector<int>> cellList;
    int cells, connections, rows, columns;
    netlist.open(filename);

    netlist >> cells;
    netlist >> connections;
    netlist >> rows;
    netlist >> columns;
    cout << cells << "\t" << connections << "\t" << rows << "\t" << columns<<"\n";
    int numberofcon;
    vector<int> netconc;
    for (int i = 0; i < connections; i++)
    {
        
        //getline(netList,test);
        netlist >> numberofcon;
        //cout << "\n" << numberofcon;
        netconc.resize(numberofcon);
        for (int j = 0; j < numberofcon; j++)
        {
            netlist >> netconc[j];
        }
        cellList.insert(pair<int, vector<int>>(numberofcon, netconc));
    }
    grid plan;
    plan.cellList = cellList;
    plan.info[0] = cells;
    plan.info[1] = connections;
    plan.info[2] = rows;
    plan.info[3] = columns;
    
    netlist.close();
    
}
void swap(int &x1,int &y1, int &val1,int &x2, int &y2, int &val2)
{
    int xtmp, ytmp, valtmp;
    xtmp=x1;
    ytmp = y1;
    valtmp = val1;
    x1 = x2;
    y1 = y2;
    val1 = val2;
    x2 = xtmp;
    y2 = ytmp;
    val2 = valtmp;
}
void gridcreate()
{
    grid plan;


}



int main()
{
    netl("test.txt");
    return 0;
}



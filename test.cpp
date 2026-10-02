#include <Eigen/Core>
#include <Eigen/Dense> // Includes matrices, solvers, geometry, etc.

struct Vertex;
struct Face;
struct HalfEdge;

struct Vertex{
    double x,y,z;
    HalfEdge* he; //one outgoing half edge
};

struct Face{
    HalfEdge* he; //one half edge belonging to this face
};

struct HalfEdge{
    Vertex* target;//target vertes of the directed half egdge 
    HalfEdge* twin;//opposit half edge
    HalfEdge* next;//next half edge in counter clock wise order around the face
    Face* face;// face which this half edge belongs
};

//inputs
std::vector<Eigen::Vector3i> F;
std::vector<Eigen::Vector3i> V;


std::vector<Vertex*> tabvertex;
std::vector<Face*> tabface;
std::vector<HalfEdge*> tabhalfedge;

int main(){


for(int i=0; i < V.size();i++){

    Eigen::Vector3i temp =V[i];
    Vertex* p = new Vertex;
    p->x=temp[0];
    p->y=temp[1];
    p->z=temp[2];
    p->he= nullptr;
    tabvertex.push_back(p);
    }


for (int i=0; i< F.size();i++){

    Eigen::Vector3i fi=F[i];
    Face* tempF= new Face;
    HalfEdge *HE0,*HE1,*HE2;

    HE0=new HalfEdge;
    HE1=new HalfEdge;
    HE2=new HalfEdge;

    tempF->he = HE0;
    tabface.push_back(tempF);

    //init using prt for vertices at fi
    for (int j = 0; j < F.size(); j++)
    {
        if(tabvertex[fi[j]]->he == nullptr){

            tabvertex[fi[j]]->he=HE0;
        }

    }
    
    HalfEdge* HE[3] = {HE0, HE1, HE2};

    for(int k=0;k<3;k++){
    
    // half edge init
    HE[k]->twin=nullptr;
    HE[k]->target=tabvertex[fi[(k+1)%3]];
    HE[k]->next=HE1;
    HE[k]->face=tempF;
    tabhalfedge.push_back(HE0);

    }
    //make it onlong or on n   hash table 

    for each half edge exist in the face

        if(i<indexi){
            findhalfedges(indexi,i); //if this is found you got a twin
        }


    }

}



    
    
    return 0;

}

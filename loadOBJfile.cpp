#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <eigen3/Eigen/Dense>

struct Mesh {
    std::vector<Eigen::Vector3d> vertices;
    std::vector<Eigen::Vector3i> faces;
};

bool loadOBJ(const std::string& filepath, Mesh& mesh) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return false;
    }

    mesh.vertices.clear();
    mesh.faces.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            double x, y, z;
            iss >> x >> y >> z;
            mesh.vertices.push_back(Eigen::Vector3d(x, y, z));
        } 
        else if (prefix == "f") {
            std::string vertexStr;
            std::vector<int> faceIndices;
            
            // Handles cases like f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3
            while (iss >> vertexStr) {
                size_t slashPos = vertexStr.find('/');
                int vIndex = std::stoi(vertexStr.substr(0, slashPos));
                faceIndices.push_back(vIndex - 1); // Convert 1-index to 0-index
            }

            if (faceIndices.size() == 3) {
                mesh.faces.push_back(Eigen::Vector3i(faceIndices[0], faceIndices[1], faceIndices[2]));
            }
        }
    }
    return true;
}

int main() {
    Mesh myMesh;
    if (loadOBJ("CrumpledDevelopable.obj", myMesh)) {
        std::cout << "Loaded " << myMesh.vertices.size() << " vertices and " 
                  << myMesh.faces.size() << " faces successfully." << std::endl;
    }
    return 0;
}
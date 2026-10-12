#include <open3d/Open3D.h>
#include <iostream>
#include <memory>

int main() {
    const std::string filename = "CrumpledDevelopable.obj";

    auto mesh = std::make_shared<open3d::geometry::TriangleMesh>();

    if (!open3d::io::ReadTriangleMesh(filename, *mesh)) {
        std::cerr << "Failed to load OBJ file: "
                  << filename << std::endl;
        return 1;
    }

    if (mesh->vertices_.empty() || mesh->triangles_.empty()) {
        std::cerr << "The OBJ file contains no triangle mesh."
                  << std::endl;
        return 1;
    }

    mesh->ComputeVertexNormals();

    open3d::visualization::DrawGeometries(
        {mesh},
        "OBJ Model Viewer"
    );

    return 0;
}
#include"model.h"
#include<Eigen\Dense>
#include<fstream>
#include<iostream>
Model::Model(const char* filename, const char* textureFilename){
    // triangleList = std::make_shared<std::vector<Triangle>>();
    std::vector<Eigen::Vector4f> verts_;
    std::vector<std::vector<Eigen::Vector3i>> faces_;
    std::vector<Eigen::Vector3f> norms_;
    std::vector<Eigen::Vector2f> uv_;

    std::ifstream in;
    in.open (filename, std::ifstream::in);
    if (in.fail()){
        std::cout << "load model " + std::string(filename) + " failed" << std::endl;
        return;
    };
    std::string line;
    while (!in.eof()) {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            Eigen::Vector4f v;
            for (int i=0;i<3;i++) iss >> v(i);
            v(3) = 1.f;
            verts_.push_back(v);
        } else if (!line.compare(0, 2, "f ")) {
            std::vector<Eigen::Vector3i> f;
            Eigen::Vector3i tmp;
            iss >> trash;
            while (iss >> tmp(0) >> trash >> tmp(1) >> trash >> tmp(2)) {
                for(int i = 0; i < 3; i ++)tmp(i)--;
                f.push_back(tmp);
            }
            faces_.push_back(f);
        }else if(!line.compare(0, 3, "vt ")){
            // 读取纹理颜色
            iss >> trash >> trash;
            Eigen::Vector2f uv;
            for(int i = 0; i < 2; i ++){
                iss >> uv(i);
            }
            uv_.push_back(uv);
        }else if(!line.compare(0, 3, "vn ")){
            // 读取法向量颜色
            iss >> trash >> trash;
            Eigen::Vector3f normal;
            for(int i = 0; i < 3; i ++){
                iss >> normal(i);
            }
            norms_.push_back(normal);
        }
    }

    triangleList.resize(faces_.size());
    triangleList.clear();
    
    for(int i = 0; i < faces_.size(); i ++){
        Triangle tmp;
        std::vector<Eigen::Vector3i> face = faces_[i];
        Eigen::Vector3i face_vertex_1 = face[0];
        Eigen::Vector3i face_vertex_2 = face[1];
        Eigen::Vector3i face_vertex_3 = face[2];

        tmp.points[0] = verts_[face_vertex_1(0)];
        tmp.points[1] = verts_[face_vertex_2(0)];
        tmp.points[2] = verts_[face_vertex_3(0)];

        tmp.texCoords[0] = uv_[face_vertex_1(1)];
        tmp.texCoords[1] = uv_[face_vertex_2(1)];
        tmp.texCoords[2] = uv_[face_vertex_3(1)];

        tmp.normals[0] = norms_[face_vertex_1(2)];
        tmp.normals[1] = norms_[face_vertex_2(2)];
        tmp.normals[2] = norms_[face_vertex_3(2)];


        triangleList.push_back(tmp);
    }
    vertexNum = static_cast<int>(verts_.size());
    faceNum = static_cast<int>(faces_.size());
    modelMatrix = Mat4::Identity();

    // 加载纹理（如果有）
    if(textureFilename != NULL){
        texture = new Texture(textureFilename);
    }
}

Model::~Model(){}
void Model::setShader(Shader* shader){
    this -> shader = shader;
};
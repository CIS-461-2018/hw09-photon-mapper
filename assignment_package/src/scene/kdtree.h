#pragma once
#include <la.h>
#include <scene/photon.h>

class KDNode
{
public:
    KDNode();
    ~KDNode();

    KDNode* leftChild;
    KDNode* rightChild;
    unsigned int axis; // Which axis split this node represents
    glm::vec3 minCorner, maxCorner; // The world-space bounds of this node
    std::vector<Photon> particles; // A collection of pointers to the particles contained in this node.
};

class KDTree
{
public:
    KDTree();
    ~KDTree();
    void build(const std::vector<Photon> *points);
    void clear();

    std::vector<Photon> particlesInSphere(glm::vec3 c, float r); // Returns all the points contained within a sphere with center c and radius r

    KDNode* root;
    glm::vec3 minCorner, maxCorner; // For visualization purposes
};

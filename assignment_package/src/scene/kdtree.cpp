#include "kdtree.h"

KDNode::KDNode()
    : leftChild(nullptr), rightChild(nullptr), axis(0), minCorner(), maxCorner(), particles()
{}

KDNode::~KDNode()
{
    delete leftChild;
    delete rightChild;
}

KDTree::KDTree()
    : root(nullptr)
{}

KDTree::~KDTree()
{
    delete root;
}

// Comparator functions you can use with std::sort to sort vec3s along the cardinal axes
bool xSort(Photon* a, Photon* b) { return a->pos.x < b->pos.x; }
bool ySort(Photon* a, Photon* b) { return a->pos.y < b->pos.y; }
bool zSort(Photon* a, Photon* b) { return a->pos.z < b->pos.z; }

void KDTree::build(const std::vector<Photon> *points)
{
    //TODO
}

void KDTree::clear()
{
    delete root;
    root = nullptr;
}

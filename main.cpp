#include "element.h"
#include "linear_algebra.h"
#include "mesh.h"
#include "sphere.h"
#include "readwrite.h"
#include "vec.hpp"
#include "webgl.h"
#include "halfedges.h"
#include "grid.h"
#include "vec.h"
#include "spmat.h"
#include "external/nl.h"
#include "parameterize.h"

#include <math.h>

// if square = false then boundary of parameterization will be a circle
// if square = true then boundary of parameterization will be a square
#define SQUARE true
/*
 * whether or not to use meanvalue weights for parameterization
 */
#define MEANVALUE false

using namespace flux;

int main(int argc, char **argv)
{
    std::unique_ptr<MeshBase> mesh_ptr = read_obj("../../data/lion.obj");
    Mesh<Triangle> &mesh = *static_cast<Mesh<Triangle> *>(mesh_ptr.get());

    // start time
    clock_t t1 = clock();

    // calling parameterization of the mesh
    parameterize(mesh, SQUARE, MEANVALUE);

    // final time
    clock_t t2 = clock();
    double runtime = double(t2 - t1) / double(CLOCKS_PER_SEC);
    printf("--> final time = %g sec.\n", runtime);

    Viewer viewer;
    viewer.add(mesh);
    viewer.run();
}
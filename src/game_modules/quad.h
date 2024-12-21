#include "mesh/mesh.h"

class Quad
{
private:
	Mesh* _mesh;

public:
	Quad();
	~Quad();
	
	void Render();
};
#include "vtkOSPRayRenderable.h"

#include "vtkOSPRay.h"

vtkOSPRayRenderable::vtkOSPRayRenderable(osp::Model* model)
: model(model)
{
  osp::affine3f identity;
  identity.l.vx.x = 1.0; identity.l.vx.y = 0.0; identity.l.vx.z = 0.0;
  identity.l.vy.x = 0.0; identity.l.vy.y = 1.0; identity.l.vy.z = 0.0;
  identity.l.vz.x = 0.0; identity.l.vz.y = 0.0; identity.l.vz.z = 1.0;
  identity.p.x = 0.0; identity.p.y = 0.0; identity.p.z = 0.0;
	instance = ospNewInstance(model, identity);
}
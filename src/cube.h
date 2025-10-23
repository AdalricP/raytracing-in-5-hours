#ifndef CUBEH
#define CUBEH

#include "hitable.h"

class cube : public hitable {
 public:
  cube() {}
  cube(vec3 min, vec3 max) : min_corner(min), max_corner(max) {}
  virtual bool hit(const ray& r, float t_min, float t_max,
                   hit_record& rec) const;
  vec3 min_corner;
  vec3 max_corner;
};

bool cube::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
  for (int a = 0; a < 3; a++) {
    float invD = 1.0f / r.direction()[a];
    float t0 = (min_corner[a] - r.origin()[a]) * invD;
    float t1 = (max_corner[a] - r.origin()[a]) * invD;
    if (invD < 0.0f) std::swap(t0, t1);
    t_min = t0 > t_min ? t0 : t_min;
    t_max = t1 < t_max ? t1 : t_max;
    if (t_max <= t_min) return false;
  }
  rec.t = t_min;
  rec.p = r.point_at_parameter(rec.t);
  // Compute normal (not accurate for all cases)
  vec3 outward_normal;
  for (int i = 0; i < 3; i++) {
    if (rec.p[i] == min_corner[i]) {
      outward_normal = vec3(0, 0, 0);
      outward_normal[i] = -1;
      break;
    } else if (rec.p[i] == max_corner[i]) {
      outward_normal = vec3(0, 0, 0);
      outward_normal[i] = 1;
      break;
    }
  }
  rec.normal = outward_normal;
  return true;
}

#endif
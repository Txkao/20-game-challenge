#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

struct Entity {
  Texture2D tex;
  Rectangle rect;
  Rectangle hit_box;
  Vector2 vel;
};

void init(Entity *entitiy, Texture2D e_tex);
void apply_gravity(Entity *entity, float dt);
void apply_velocity_y(Entity *entity, float dt);
void jump(Entity *entity);
void update(Entity *entity, float dt);
void update_hitbox(Entity *entity);

#endif // ENTITY_H

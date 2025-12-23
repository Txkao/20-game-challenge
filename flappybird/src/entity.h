#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

struct Entity {
  Texture2D tex;
  Rectangle rect;
  Vector2 vel;

  Rectangle hitbox_offset;
};

void init(Entity *entitiy, Texture2D e_tex, Vector2 pos);
void apply_gravity(Entity *entity, float dt);
void apply_velocity_y(Entity *entity, float dt);
void apply_velocity_x(Entity *entity, float dt, int move_speed);
void jump(Entity *entity);
void update(Entity *entity, float dt);

Rectangle get_hitbox(const Entity *entity);

#endif // ENTITY_H

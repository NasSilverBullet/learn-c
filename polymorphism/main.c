#include "stdio.h"
#include "stdlib.h"

typedef void (*fptrSet)(void *, int);
typedef int (*fptrGet)(void *);
typedef void (*fptrDisplay)();

typedef struct _functions {
  fptrSet setX;
  fptrGet getX;
  fptrSet setY;
  fptrGet getY;
  fptrDisplay display;
} vFunctions;

typedef struct _shape {
  vFunctions functions;
  int x;
  int y;
} Shape;

void shapeDisplay() { printf("Shape\n"); }
void shapeSetX(Shape *shape, int x) { shape->x = x; }
int shapeGetX(Shape *shape) { return shape->x; }
void shapeSetY(Shape *shape, int y) { shape->y = y; }
int shapeGetY(Shape *shape) { return shape->y; }

Shape *getShapeInstance() {
  Shape *shape = (Shape *)malloc(sizeof(Shape));

  shape->functions.display = (fptrDisplay)shapeDisplay;
  shape->functions.setX = (fptrSet)shapeSetX;
  shape->functions.getX = (fptrGet)shapeGetX;
  shape->functions.setY = (fptrSet)shapeSetY;
  shape->functions.getY = (fptrGet)shapeGetY;

  shape->x = 100;
  shape->y = 100;

  return shape;
}

typedef struct _rectangle {
  Shape base;
  int width;
  int height;
} Rectangle;

void rectangleDisplay() { printf("Rectangle\n"); }
void rectangleSetX(Rectangle *rectangle, int x) { rectangle->base.x = x; }
int rectangleGetX(Rectangle *rectangle) { return rectangle->base.x; }
void rectangleSetY(Rectangle *rectangle, int y) { rectangle->base.y = y; }
int rectangleGetY(Rectangle *rectangle) { return rectangle->base.y; }

Rectangle *getRectangleInstance() {
  Rectangle *rectangle = (Rectangle *)malloc(sizeof(Rectangle));

  rectangle->base.functions.display = (fptrDisplay)rectangleDisplay;
  rectangle->base.functions.setX = (fptrSet)rectangleSetX;
  rectangle->base.functions.getX = (fptrGet)rectangleGetX;
  rectangle->base.functions.setY = (fptrSet)rectangleSetY;
  rectangle->base.functions.getY = (fptrGet)rectangleGetY;

  rectangle->base.x = 100;
  rectangle->base.y = 100;

  rectangle->height = 100;
  rectangle->width = 100;

  return rectangle;
}

int main() {
  Shape *shapes[3];

  shapes[0] = getShapeInstance();
  shapes[0]->functions.setX(shapes[0], 35);

  shapes[1] = (Shape *)getRectangleInstance();
  shapes[1]->functions.setX(shapes[1], 45);

  shapes[2] = getShapeInstance();
  shapes[2]->functions.setX(shapes[2], 55);

  for (int i = 0; i < (sizeof(shapes) / sizeof(Shape *)); i++) {
    shapes[i]->functions.display();
    printf("%d\n", shapes[i]->functions.getX(shapes[i]));
  }
}


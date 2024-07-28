#include <Engine/pathfinder.hpp>

namespace Game {
  Pathfinder::Pathfinder() {};

  bool Pathfinder::isStopped() {
    return this->paths.empty();
  };

  void Pathfinder::setDestiny(Vector<float> position) {
    this->current_segment = Segment();
    while(!this->paths.empty()) {
      this->paths.pop();
    };

    Vector4<Segment> segments = this->getNearestSegments(position);
    float x1 = segments.x.start.x;
    float y1 = segments.y.start.y;
    float x2 = segments.y.start.x;
    float y2 = segments.z.start.y;
    
    if(
      x1 < position.x && position.x < x2 &&
      y1 < position.y && position.y < y2
    ) {
      Vector<float> vertex[3] = {
        segments.y.start,
        segments.z.start,
        segments.w.start
      };

      Vector<float> nearest = segments.x.start;
      double distance = Math::pointDistance(nearest, position);
      for(unsigned short int i = 0; i < 3; i++) {
        double new_distance = Math::pointDistance(vertex[i], position);
        if(new_distance < distance) {
          distance = new_distance;
          nearest = vertex[i];
        };
      };

      float xx = abs(nearest.x - position.x);
      float yy = abs(nearest.y - position.y);

      if(xx < yy) {
        nearest.y = position.y;
      } else if(yy < xx) {
        nearest.x = position.x;
      };

      this->paths.push(nearest);
    } else {
      this->paths.push(position);
    };
  };

  Vector4<Segment> Pathfinder::getNearestSegments(Vector<float> position) {
    Vector<float> towers_positions[3] = {
      BOTTOM_LEFT_TOWER_POSITION, 
      TOP_RIGHT_TOWER_POSITION, 
      BOTTOM_RIGHT_TOWER_POSITION
    };

    Vector<float> tower_position = TOP_LEFT_TOWER_POSITION;
    double distance_to_tower = Math::pointDistance(tower_position, position);
    for(unsigned short int i = 0; i < 3; i++) {
      double new_distance_to_tower = Math::pointDistance(towers_positions[i], position);
      if(new_distance_to_tower < distance_to_tower) {
        distance_to_tower = new_distance_to_tower;
        tower_position = towers_positions[i];
      };
    };

    float min_distance = (TOWER_SIZE/2.0) + 11;
    Segment ab(
      tower_position + Vector<float>(-min_distance, -min_distance), 
      tower_position + Vector<float>(min_distance, -min_distance)
    );
    Segment bc(
      tower_position + Vector<float>(min_distance, -min_distance), 
      tower_position + Vector<float>(min_distance, min_distance)
    );
    Segment cd(
      tower_position + Vector<float>(min_distance, min_distance), 
      tower_position + Vector<float>(-min_distance, min_distance)
    );
    Segment da(
      tower_position + Vector<float>(-min_distance, min_distance), 
      tower_position + Vector<float>(-min_distance, -min_distance)
    );

    return Vector4<Segment>(ab, bc, cd, da);
  };

  Vector3<double> Pathfinder::getDestiny(Vector<float> position, double direction, float speed) {
    if(this->paths.empty()) {
      return Vector3<double>(position.x, position.y, direction);
    };

    Vector<float> destiny = this->paths.top();
    if(destiny != position) {
      double distance = Math::pointDistance(destiny, position);
      Vector<float> difference = destiny - position;
      direction = Math::pointDirection(difference);
      Vector<float> destiny = position + Math::pointInRadius(
        min(double(speed), distance), 
        direction
      );

      Vector4<Segment> segments = this->getNearestSegments(position);
      Segment path(position, destiny);
      Segment ab = segments.x;
      Segment bc = segments.y;
      Segment cd = segments.z;
      Segment da = segments.w;

      if(Math::hasIntersection(ab, path) && destiny.y > ab.start.y && ab != current_segment) {
        this->current_segment = ab;
        this->paths.push(ab.getNearestVertex(this->paths.top()));
        return this->getDestiny(position, direction, speed);
      } else if(Math::hasIntersection(bc, path) && destiny.x < bc.start.x && bc != current_segment) {
        this->current_segment = bc;
        this->paths.push(bc.getNearestVertex(this->paths.top()));
        return this->getDestiny(position, direction, speed);
      } else if(Math::hasIntersection(cd, path) && destiny.y < cd.start.y && cd != current_segment) {
        this->current_segment = cd;
        this->paths.push(cd.getNearestVertex(this->paths.top()));
        return this->getDestiny(position, direction, speed);
      } else if(Math::hasIntersection(da, path) && destiny.x > da.start.x && da != current_segment) {
        this->current_segment = da;
        this->paths.push(da.getNearestVertex(this->paths.top()));
        return this->getDestiny(position, direction, speed);
      };
      
      return Vector3<double>(destiny.x, destiny.y, direction);
    } else {
      this->paths.pop();
      return this->getDestiny(position, direction, speed);
    };
  };
};
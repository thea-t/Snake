#ifndef DIRECTION_H
#define DIRECTION_H

    //#######################################################
    //    Class         :    Direction
    //    Purpose       :    Holds an enum of direction that the snake uses to determine which direction to move to.
    //    Parameters    :    None
    //    Returns       :    enum
    //    Notes         :     Warnings prevented by using: https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
    //    See also      :    Snake::tryMove(), Snake::setDirection(), Snake::readInput()
    //#######################################################

enum class Direction { None, Left, Right, Up, Down };

#endif
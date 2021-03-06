/*
The MIT License (MIT)

Copyright (c) 2017-2018 Florian Eith <florian.eith@web.de>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef RCLL_ROBOT_MARKER_H
#define RCLL_ROBOT_MARKER_H

#include <util.h>
#include <Arrow.h>
#include <Circle.h>
#include <Line.h>
#include <BoxLabel.h>

#include <rcll_vis_msgs/Robot.h>

namespace rcll_draw {
    class RobotMarker {
    public:
        RobotMarker();
        RobotMarker(Team team);
        ~RobotMarker();

        void setOrigin(int origin_x, int origin_y, int pixel_per_meter);
        void setRefBoxView(bool refbox_view);
        void setRobot(rcll_vis_msgs::Robot &robot);
        void draw(cv::Mat &mat);

    private:
        int pixel_per_meter = 10;
        int origin_x, origin_y = 0;

        rcll_vis_msgs::Robot robot;
        double diameter;
        bool pose_set = false;
        bool refbox_view;

        Circle crc_robot;
        Line ln_direction;
        BoxLabel blbl_id;
        Arrow arr_heading;
    };
}

#endif

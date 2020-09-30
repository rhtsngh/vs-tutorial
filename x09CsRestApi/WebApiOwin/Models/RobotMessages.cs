using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WebApiOwin.Models
{
    class RobotMessages
    {
    }

    //=========================================================================
    //Minh added 20200924: Model of Request
    public enum MState
    {
        off = 0,
        on = 1
    }
    public enum MJogType
    {
        off = 0,
        on = 1
    }
    public enum MDirection
    {
        backward = -1,
        none = 0,
        forward = 1
    }
    public class MJogDirections
    {
        public MDirection d1 { get; set; }
        public MDirection d2 { get; set; }
        public MDirection d3 { get; set; }
        public MDirection d4 { get; set; }
        public MDirection d5 { get; set; }
        public MDirection d6 { get; set; }
    }
    public enum MPositionType
    {
        joint = 0,
        cartesian = 1,
        all = 2
    }
    public enum MAngleType
    {
        degree = 0,
        radian = 1
    }
    public class MJoint
    {
        public MAngleType type { get; set; }
        public float j1 { get; set; }
        public float j2 { get; set; }
        public float j3 { get; set; }
        public float j4 { get; set; }
        public float j5 { get; set; }
        public float j6 { get; set; }
    }
    public enum MUnitType
    {
        m = 0,
        mm = 1
    }
    public enum MOrientationType
    {
        degree = 0,
        radian = 1
    }
    public class MCartesian
    {
        public MUnitType unit_type { get; set; }
        public MOrientationType orientation_type { get; set; }
        public float x { get; set; }
        public float y { get; set; }
        public float z { get; set; }
        public float a { get; set; }
        public float b { get; set; }
        public float c { get; set; }
    }
    public class MPosition
    {
        public MJoint joint { get; set; }
        public MCartesian cartesian { get; set; }
    }
    public enum MMoveType
    {
        movel = 0,
        movej = 1,
        movejc = 2
    }
    public enum MPathAction
    {
        clear = 0,
        add = 1,
        execute = 2
    }
    public class MRequest
    {
        public string state { get; set; }
        public string jog_type { get; set; }
        public MJogDirections jog_directions { get; set; }
        public float speed { get; set; }
        public MPositionType position_type { get; set; }
        public MMoveType move_type { get; set; }
        public MPosition position { get; set; }
        public MPathAction path_action;
    }

    //=========================================================================
    //Minh added 20200924: Model of Response
    public class MResponse
    {
        public bool? status { get; set; }
        public MPosition position { get; set; }
    }
}

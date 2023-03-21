class JointInfo {
    public:
        double minimum;
        double maximum;

        JointInfo() { 
            
        }

        JointInfo(double min, double max) { 
            minimum = min;
            maximum = max;
        }
        void set_minimum (double min){
            minimum = min;
        }

        void set_maximum(double max) {
            maximum = max;
        }
    
};

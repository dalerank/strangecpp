int baadcommnent() {
    std::string hello_world = "hello world";
    if (hello_world.compare("hello world‮ ⁦// Check this is correct⁩ ⁦"))
    {
        printf("goodbye world");
    }
}

// This code was used in the Unity 2014 engine to control the rotation of objects using a gizmo (a control element,
// usually in the form of three circles, that allows you to rotate an object in the scene). In this case, the setDeltaPitch 
// function is applied to change the pitch angle of the object relative to its vertical axis. At angles close to 0 
// (depending on the editor settings), it would simply flip the object upside down, which really annoyed the level designers. First one here ^)
void	UObject::setDeltaPitch(const UMatrix &gizmo) {       
		//....

		if (_fpzero(amount, eps))
			return

		rotateAccum.setAnglesXYZ(axis);
        //....
}

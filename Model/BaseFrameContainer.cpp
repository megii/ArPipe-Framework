//
//  BaseFrameContainer.cpp
//  AR
//
//  Created by Menger David on 17.03.13.
//  Copyright (c) 2013 storyous.com s.r.o. All rights reserved.
//

#include "BaseFrameContainer.h"

namespace ArPipe {
    
    BaseFrameContainer::BaseFrameContainer(Frame *frm) {
        frame = frm;
    }

    Frame* BaseFrameContainer::getFrame()
    {
        return frame;
    }
    
    BaseFrameContainer::~BaseFrameContainer()
    {
        delete frame;
    }
    
}
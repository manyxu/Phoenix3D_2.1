//
//  Shader.fsh
//  AppPlay
//
//  Created by 许多 on 15-2-19.
//  Copyright (c) 2015年 Phoenix. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}

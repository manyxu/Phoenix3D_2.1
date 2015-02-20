//
//  ViewController.m
//  AppPlay
//
//  Created by 许多 on 15-2-19.
//  Copyright (c) 2015年 Phoenix. All rights reserved.
//

#import "ViewController.h"
#include "AppPlay.hpp"

const char *GetBundleFileName (const char *pszRelativePath)
{
    NSString *fullpath = nil;
    NSString *relPath = [NSString stringWithUTF8String:pszRelativePath];
    
    // only if it is not an absolute path
    if( ! [relPath isAbsolutePath] )
    {
        NSString *file = [relPath lastPathComponent];
        NSString *imageDirectory = [relPath stringByDeletingLastPathComponent];
        
        fullpath = [[NSBundle mainBundle] pathForResource:file
												   ofType:nil
											  inDirectory:imageDirectory];
    }
    
    if (fullpath == nil)
    {
        fullpath = relPath;
    }
    
    return [fullpath UTF8String];

}

@interface ViewController ()
{
}
@property (strong, nonatomic) EAGLContext *context;

- (void)setupGL;
- (void)tearDownGL;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];

    if (!self.context) {
        NSLog(@"Failed to create ES context");
    }
    
    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    
    [self setupGL];
    
    std::string path = GetBundleFileName("Data/boost.xml");
    
    NSString *resPath = [[NSBundle mainBundle] resourcePath];
    std::string strResPath = [resPath UTF8String];
    strResPath.append("/");
    appplay::NativeCall::SetResourcePath(strResPath);
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    std::string strRet = [documentsDirectory UTF8String];
    strRet.append("/");
    appplay::NativeCall::SetWriteablePath(strRet);

    appplay::NativeCall::Initlize(960, 640);
}

- (void)dealloc
{    
    [self tearDownGL];
    
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];

    if ([self isViewLoaded] && ([[self view] window] == nil)) {
        self.view = nil;
        
        [self tearDownGL];
        
        if ([EAGLContext currentContext] == self.context) {
            [EAGLContext setCurrentContext:nil];
        }
        self.context = nil;
    }

    // Dispose of any resources that can be recreated.
}

- (void)setupGL
{
    [EAGLContext setCurrentContext:self.context];
}

- (void)tearDownGL
{
    [EAGLContext setCurrentContext:self.context];
}

- (void)update
{
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    appplay::NativeCall::OnOdle();

}

@end
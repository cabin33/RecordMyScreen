//
//  CSRecordViewController.h
//  RecordMyScreen
//
//  Created by @coolstarorg on 12/29/12.
//  Copyright (c) 2012 CoolStar Organization. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <IOSurface.h>

@interface CSRecordViewController : UIViewController <AVAudioRecorderDelegate> {
    bool _isRecording;
    UISegmentedControl *_record,*_stop;
    IBOutlet UIImageView *_recordbar;
    IBOutlet UILabel *_statusLabel;
    IBOutlet UIProgressView *_progressView;
    NSTimer *_recordingTimer;
    NSDate *_recordStartDate;
    AVAudioRecorder *_audioRecorder;
    NSString *_shotdir;
    int shotcount;
    NSMutableArray *_shotQueue;
    
    //surface
    IOSurfaceRef _surface;
    int _bytesPerRow;
    int _width;
    int _height;
    
    
    //video writing
    int _fps;
    NSLock *_pixelBufferLock;
    AVAssetWriter *_videoWriter;
    AVAssetWriterInput *_videoWriterInput;
    AVAssetWriterInputPixelBufferAdaptor *_pixelBufferAdaptor;
}

- (void)createScreenSurface;
- (void)captureShot:(CMTime)frameTime;
- (void)setupVideoContext;
@end

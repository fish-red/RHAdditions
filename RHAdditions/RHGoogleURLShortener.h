//
//  RHGoogleURLShortener.h
//
//  Created by Richard Heard on 25/05/13.
//  Copyright (c) 2013 Richard Heard. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//  1. Redistributions of source code must retain the above copyright
//  notice, this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the
//  documentation and/or other materials provided with the distribution.
//  3. The name of the author may not be used to endorse or promote products
//  derived from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
//  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
//  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <Foundation/Foundation.h>

//you must define your google service API key to use this class eg:
//#define RH_GOOGLE_URL_SHORTENER_API_KEY @"YOUR_API_KEY_HERE"

typedef void (^RHGoogleURLShortenerCompletionBlock)(NSURL *shortURL, NSError *error);
//if shortening fails, we return nil and set error!

@interface RHGoogleURLShortener : NSObject {
    //ivars be private
    RHGoogleURLShortenerCompletionBlock _completionBlock;
    NSURL *_originalURL;
    NSMutableData *_mutableData;
    NSURLConnection *_connection;
    id _retainedSelf;
}

+(id)shortenURL:(NSURL*)url withCompletion:(RHGoogleURLShortenerCompletionBlock)completion;
-(void)cancel;

@end

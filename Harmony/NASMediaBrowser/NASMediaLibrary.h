//
//  PhotoLibrary.h
//  NASClient
//
//  Created by wang zhenbin on 1/12/13.
//  Copyright (c) 2013 merry99. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ProtocolInfo : NSObject {
    NSString* protocol;
    NSString* contentType;
}

@property (retain) NSString* protocol;
@property (retain) NSString* contentType;

- (NSString *)description;
@end

@interface Resource: NSObject {
    NSString*       uri;
    ProtocolInfo*   protocolInfo;
    NSInteger       size;
    NSString*       resolution;
}

@property (retain) NSString*       uri;
@property (retain) ProtocolInfo*   protocolInfo;
@property (assign) NSInteger        size;
@property (retain) NSString*       resolution;

- (NSString *)description;
@end

@class MediaCategory;
@interface MediaObject : NSObject {
    NSString* title;
    NSString* id;
    MediaCategory *parentCategory;
}

@property (retain) NSString* title;
@property (retain) NSString* id;
@property (retain) MediaCategory *parentCategory;

- (NSString *)getThumbnailURL;
- (NSString *)getResizedURL;
- (NSString *)getMediaURL;
- (NSString *)description;
@end

@interface MediaCategory : MediaObject {
    NSInteger   childrenCount;
}

@property (assign) NSInteger childrenCount;

- (NSString *)description;

@end

@interface MediaItem : MediaObject {
    NSString* creator;
    NSString* date;
    NSArray* resources;
}

@property (retain) NSString* creator;
@property (retain) NSString* date;
@property (retain) NSArray* resources;

- (NSString *)description;
@end

@interface User : NSObject {
    NSString* name;
    NSString* sn;
}

@property (retain) NSString* name;
@property (retain) NSString* sn;

- (NSString *)description;
@end

@interface Friend : User {
    BOOL isOnline;
    BOOL isShield;
    BOOL isShared;
}

@property (assign) BOOL isOnline;
@property (assign) BOOL isShield;
@property (assign) BOOL isShared;

- (NSString *)description;
@end

@interface NASMediaLibrary : NSObject
+ (NSInteger) initWithUser:(NSString*) user password:(NSString*) passwd;
+ (BOOL) isRemoteAccess;
+ (BOOL) reconnect;
+ (void) closeConnection;
+ (NSString *)getServerBaseURL;
+ (NSString *)getLoginedUserName;

//media interface
+ (NSArray *) getMediaCategories;
+ (NSArray *) getMediaObjects:(MediaCategory *)catogery;
+ (NSArray *) getMediaObjects:(MediaCategory *)catogery withMaxResults:(int)maxResults;

 //social interface
+ (NSArray *) getFriendList;
+ (BOOL) shareFolder:(NSString *)folder withFriends:(NSArray *)friends;
+ (BOOL) unshareFolder:(NSString *)folder withFriends:(NSArray *)friends;
+ (NSArray *) getAllShareFolders;
+ (NSArray *) getFriendsSharedWithFolder:(NSString *)folder;
+ (NSArray *) getSubFolders:(NSString *)folder;

//management interface
+ (BOOL) tagFavoriteObjects:(NSArray *)favors;
+ (BOOL) untagFavoriteObjects:(NSArray *)unFavors;
+ (NSString *)shareAlbumWithFiles:(NSArray *)files;
+ (BOOL) commitPrinttaskForFiles:(NSArray *)files;
+ (NSArray *) getNASMessages;

//file data exchange interface
+ (NSData *) getVCardData;
+ (BOOL) backupVCardData:(NSData *)vCardData;
+ (BOOL) backupPhotoData:(NSData *)photoData withName:(NSString *)name;
@end

//
//  GITRepository.h
//  GitHubAPIClient
//
//  Created by hao on 6/29/15.
//  Copyright (c) 2015 hao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GitHubOAuthClient.h"
#import "GITBaseModel.h"
#import "GITUser.h"

typedef NS_ENUM(NSUInteger, JGHRepositoryType) {
    JGHRepositoryTypeAll,
    JGHRepositoryTypeOwner,
    JGHRepositoryTypePublic,
    JGHRepositoryTypePrivate,
    JGHRepositoryTypeMember,
    JGHRepositoryTypeForks,
    JGHRepositoryTypeSources
};

typedef NS_ENUM(NSUInteger, JGHRepositorySortBy) {
    JGHRepositorySortByCreated,
    JGHRepositorySortByUpdated,
    JGHRepositorySortByPushed,
    JGHRepositorySortByFullname
};

typedef NS_ENUM(NSUInteger, JGHRepositoryOrderBy) {
    JGHRepositoryOrderByAsc,
    JGHRepositoryOrderByDesc,
};

@interface GITRepository : GITBaseModel

@property (nonatomic, assign          ) NSUInteger forksCount;
@property (nonatomic, assign          ) NSUInteger watchersCount;
@property (nonatomic, assign          ) NSUInteger stargazersCount;
@property (nonatomic, assign          ) NSUInteger openIssuesCount;
@property (nonatomic, assign          ) NSUInteger ID;
@property (nonatomic, assign          ) NSUInteger size;
@property (nonatomic, strong          ) GITUser    *owner;
@property (nonatomic, readonly, strong) NSURL      *url;
@property (nonatomic, readonly, strong) NSURL      *cloneURL;
@property (nonatomic, readonly, strong) NSURL      *mirrorURL;
@property (nonatomic, readonly, strong) NSURL      *homepage;
@property (nonatomic, readonly, strong) NSURL      *htmlURL;
@property (nonatomic, readonly, strong) NSURL      *gitURL;
@property (nonatomic, readonly, strong) NSURL      *svnURL;
@property (nonatomic, readonly, strong) NSURL      *sshURL;
@property (nonatomic, assign          ) BOOL       isForked;
@property (nonatomic, assign          ) BOOL       hasDownloads;
@property (nonatomic, assign          ) BOOL       hasWiki;
@property (nonatomic, assign          ) BOOL       hasPages;
@property (nonatomic, assign          ) BOOL       hasIssues;
@property (nonatomic, assign          ) BOOL       isAdmin;
@property (nonatomic, assign          ) BOOL       canPush;
@property (nonatomic, assign          ) BOOL       canPull;
@property (nonatomic, assign          ) BOOL       isPrivate;
@property (nonatomic, readonly, copy  ) NSString   *desc;
@property (nonatomic, readonly, copy  ) NSString   *defaultBranch;
@property (nonatomic, readonly, copy  ) NSString   *name;
@property (nonatomic, readonly, copy  ) NSString   *fullName;
@property (nonatomic, readonly, copy  ) NSString   *language;
@property (nonatomic, readonly, strong) NSDate     *updatedAt;
@property (nonatomic, readonly, strong) NSDate     *createdAt;
@property (nonatomic, readonly, strong) NSDate     *pushedAt;

+ (BOOL)isStarredRepo:(GITRepository *)repo;

+ (NSArray *)myStarredRepositories;

+ (void)updateMyStarredRepositories:(NSArray *)repos;

+ (NSArray *)myOwnedRepositories;

+ (AFHTTPRequestOperation *)myRepositoriesWithSuccess:(void (^)(NSArray *))success
                                              failure:(GitHubClientFailureBlock)failure;

+ (AFHTTPRequestOperation *)repositoriesOfUser:(NSString *)user
                                          type:(JGHRepositoryType)type
                                        sortBy:(JGHRepositorySortBy)sortBy
                                       orderBy:(JGHRepositoryOrderBy)orderBy
                                       success:(void (^)(NSArray *))success
                                       failure:(GitHubClientFailureBlock)failure;

+ (AFHTTPRequestOperation *)repositoriesOfUser:(NSString *)user
                                       success:(void (^)(NSArray *))success
                                       failure:(GitHubClientFailureBlock)failure;

+ (AFHTTPRequestOperation *)repositoriesOfOrganization:(NSString *)org
                                               success:(void (^)(NSArray *))success
                                               failure:(GitHubClientFailureBlock)failure;

+ (AFHTTPRequestOperation *)publicRepositoriesSince:(NSString *)since
                                            success:(void (^)(NSArray *))success
                                            failure:(GitHubClientFailureBlock)failure;

+ (AFHTTPRequestOperation *)starredRepositoriesByUser:(NSString *)user
                                              success:(void (^)(NSArray *))success
                                              failure:(GitHubClientFailureBlock)failure;

// https://developer.github.com/v3/repos/forks/#list-forks
//+ (AFHTTPRequestOperation *)forksOfRepository:(GITRepository *)repo
//                                      success:(void (^)(NSArray *))success
//                                      failure:(GitHubClientFailureBlock)failure;

// https://developer.github.com/v3/repos/forks/#list-forks
+ (AFHTTPRequestOperation *)forksOfRepository:(NSString *)repoName
                                      success:(void (^)(NSArray *))success
                                      failure:(GitHubClientFailureBlock)failure;


+ (AFHTTPRequestOperation *)starRepository:(GITRepository *)repo
                                   success:(void (^)(BOOL))success
                                   failure:(GitHubClientFailureBlock)failure;

+ (AFHTTPRequestOperation *)unstarRepository:(GITRepository *)repo
                                     success:(void (^)(BOOL))success
                                     failure:(GitHubClientFailureBlock)failure;

+ (AFHTTPRequestOperation *)watchRepository:(GITRepository *)repo
                                    success:(void (^)(BOOL))success
                                    failure:(GitHubClientFailureBlock)failure;

+ (AFHTTPRequestOperation *)unwatchRepository:(GITRepository *)repo
                                    success:(void (^)(BOOL))success
                                    failure:(GitHubClientFailureBlock)failure;

//+ (AFHTTPRequestOperation *)forkRepository:(GITRepository *)repo
//                                   success:(void (^)(NSArray *))success
//                                   failure:(GitHubClientFailureBlock)failure;

- (AFHTTPRequestOperation *)readmeWithsuccess:(void (^)(NSString *))success
                                      failure:(GitHubClientFailureBlock)failure
                                  needRefresh:(BOOL)refresh;

@end

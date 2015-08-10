#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface IGUser : NSObject
	@property (strong, nonatomic) NSString *username;
	+(void)fetchFollowStatusInBulk:(id)fp8;
	-(id)followingCount;
	-(id)followerCount;
	-(void)fetchAdditionalUserDataWithCompletion:(id)fp8;
	-(void)fetchFollowStatus;
@end

@interface IGPost : NSObject
	@property (strong, nonatomic) IGUser *user;
	-(id)init;
	-(id)initWithCoder:(id)fp8;
	-(int)likeCount;
@end

@interface IGFeedItem : IGPost
-(id)description;
-(BOOL)isHidden;
-(id)getMediaId;
-(void)setIsHidden:(BOOL)hidden;
-(id)initWithCoder:(id)fp8;
-(id)init;
-(id)buildLikersStyledStringForType:(unsigned int)type;
@end

@interface IGFeedItemActionCell
-(BOOL)sponsoredPostAllowed;
-(id)initWithFrame:(CGRect)frame;
-(UIButton*)likeButton;
@end

@interface AppDelegate : NSObject
- (void)startMainAppWithMainFeedSource:(id)source animated:(BOOL)animated;
- (id)window; 
@end

@interface IGMainFeedViewController
-(BOOL)shouldHideFeedItem:(id)fp8;
-(BOOL)isFirstFeedLoad;
-(void)setIsFirstFeedLoad:(BOOL)first;
@end

@interface IGCollectionViewController
-(void)onPullToRefresh:(id)fp8;
-(void)finishRefreshFromPullToRefreshControl;
@end

@interface IGFeedViewController
-(void)handleDidDisplayFeedItem:(IGFeedItem*)item;
@end

@interface IGViewController : UIViewController
@end

@interface IGUserDetailViewController : IGViewController
-(void)actionSheetDismissedWithButtonTitled:(NSString *)title;
-(IGUser *)user;
@end

@interface IGRootViewController : UIViewController
- (id)topMostViewController;
@end

@interface IGStyledString
@property(retain, nonatomic) NSMutableAttributedString *attributedString;
-(void)appendString:(id)str;
-(void)appendAttributedString:(id)styled;
@end

@interface IGCoreTextView : UIView
@property(retain, nonatomic) IGStyledString *styledString;
@end

@interface IGFeedItemTextCell
-(IGStyledString*)styledStringForLikesWithFeedItem:(IGFeedItem*)item;
-(IGCoreTextView*)coreTextView;
-(void)layoutSubviews;
-(int)accessibilityElementCount;
-(id)accessibilityElementAtIndex:(int)index;
@end

@interface IGShakeWindow : UIWindow
- (id)rootViewController;
@end

@interface IGActionSheet
- (void)addButtonWithTitle:(NSString *)title style:(int)style;
@end

@interface IGFeedItemHeader
-(BOOL)sponsoredPostAllowed;
@end

@interface IGFeedItemTimelineLayoutAttributes
-(BOOL)sponsoredContext;
@end

@interface IGSponsoredPostInfo
-(BOOL)showIcon;
-(BOOL)hideCommentButton;
-(BOOL)isHoldout;
-(BOOL)hideComments;
@end
//
//  Copyright (c) 2018 Open Whisper Systems. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

// TODO: Remove this enum.
typedef NS_ENUM(NSInteger, ConversationViewLayoutAlignment) {
    // We use incoming/outgoing, not left/right to support RTL.
    ConversationViewLayoutAlignment_Incoming,
    ConversationViewLayoutAlignment_Outgoing,
    ConversationViewLayoutAlignment_FullWidth,
    ConversationViewLayoutAlignment_Center,
};

@class ConversationLayoutInfo;

@protocol ConversationViewLayoutItem <NSObject>

- (CGSize)cellSize;

- (ConversationViewLayoutAlignment)layoutAlignment;

- (CGFloat)vSpacingWithLastLayoutItem:(id<ConversationViewLayoutItem>)lastLayoutItem;

@end

#pragma mark -

@protocol ConversationViewLayoutDelegate <NSObject>

- (NSArray<id<ConversationViewLayoutItem>> *)layoutItems;

- (CGFloat)layoutHeaderHeight;

@end

#pragma mark -

// A new lean and efficient layout for conversation view designed to
// handle our edge cases (e.g. full-width unread indicators, etc.).
@interface ConversationViewLayout : UICollectionViewLayout

@property (nonatomic, weak) id<ConversationViewLayoutDelegate> delegate;
@property (nonatomic, readonly) BOOL hasLayout;
@property (nonatomic, readonly) BOOL hasEverHadLayout;
@property (nonatomic, readonly) ConversationLayoutInfo *layoutInfo;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithLayoutInfo:(ConversationLayoutInfo *)layoutInfo;

@end

NS_ASSUME_NONNULL_END

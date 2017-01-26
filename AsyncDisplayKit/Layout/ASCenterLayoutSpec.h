//
//  ASCenterLayoutSpec.h
//  AsyncDisplayKit
//
//  Copyright (c) 2014-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under the BSD-style license found in the
//  LICENSE file in the root directory of this source tree. An additional grant
//  of patent rights can be found in the PATENTS file in the same directory.
//

#import <AsyncDisplayKit/ASRelativeLayoutSpec.h>

/** 
  * How the child is centered within the spec.
  *
  * None - The child is positioned in {0,0} relatively to the layout bound. 
  * X    - The child is centered along the X axis
  * Y    - The child is centered along the Y axis
  * XY   - Convenience option to center both along the X and Y axis
  */
typedef NS_OPTIONS(NSUInteger, ASCenterLayoutSpecCenteringOptions) {
  ASCenterLayoutSpecCenteringNone = 0,
  ASCenterLayoutSpecCenteringX = 1 << 0,
  ASCenterLayoutSpecCenteringY = 1 << 1,
  ASCenterLayoutSpecCenteringXY = ASCenterLayoutSpecCenteringX | ASCenterLayoutSpecCenteringY
};

/** 
  * How much space the spec will take up.
  *
  * Default   - The spec will take up the maximum size possible
  * MinimumX  - The spec will take up the minimum size possible along the X axis
  * MinimumY  - The spec will take up the minimum size possible along the Y axis
  * MinimumXY - Convenience option to take up the minimum size along both the X and Y axis
  */
typedef NS_OPTIONS(NSUInteger, ASCenterLayoutSpecSizingOptions) {
  ASCenterLayoutSpecSizingOptionDefault = ASRelativeLayoutSpecSizingOptionDefault,
  ASCenterLayoutSpecSizingOptionMinimumX = ASRelativeLayoutSpecSizingOptionMinimumWidth,
  ASCenterLayoutSpecSizingOptionMinimumY = ASRelativeLayoutSpecSizingOptionMinimumHeight,
  ASCenterLayoutSpecSizingOptionMinimumXY = ASRelativeLayoutSpecSizingOptionMinimumSize
};

NS_ASSUME_NONNULL_BEGIN

/** Lays out a single layoutElement child and position it so that it is centered into the layout bounds.
  * NOTE: ASRelativeLayoutSpec offers all of the capabilities of Center, and more.
  * Check it out if you would like to be able to position the child at any corner or the middle of an edge.
 */
@interface ASCenterLayoutSpec : ASRelativeLayoutSpec

@property (nonatomic, assign) ASCenterLayoutSpecCenteringOptions centeringOptions;
@property (nonatomic, assign) ASCenterLayoutSpecSizingOptions sizingOptions;

/**
 * Initializer.
 *
 * @param centeringOptions How the child is centered.
 * @param sizingOptions How much space will be taken up.
 * @param child The child to center.
 */
+ (instancetype)centerLayoutSpecWithCenteringOptions:(ASCenterLayoutSpecCenteringOptions)centeringOptions
                                       sizingOptions:(ASCenterLayoutSpecSizingOptions)sizingOptions
                                               child:(id<ASLayoutElement>)child AS_WARN_UNUSED_RESULT;

@end

NS_ASSUME_NONNULL_END

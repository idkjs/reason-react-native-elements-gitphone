/** 
 * @flow strict
 * @generated
 * @nolint
 */
/* eslint-disable */
// $FlowExpectedError: Reason checked type sufficiently
type $any = any;

// flowlint-next-line nonstrict-import:off
import {Avatar as Avatar} from 'react-native-elements';

// $FlowExpectedError: Reason checked type sufficiently
import * as React from 'react';

// $FlowExpectedError: Reason checked type sufficiently
import * as ReasonReact from 'reason-react/src/ReasonReact.js';

export type Props = {|
  +source: source, 
  +size: string, 
  +rounded: boolean
|};

// In case of type error, check the type of 'make' in 'RNAvatar.re' and the props of 'react-native-elements'.
export function AvatarTypeChecked(props: Props) {
  return <Avatar {...props}/>;
}

// Export 'make' early to allow circular import from the '.bs.js' file.
export const make: mixed = function (source: $any, size: $any, rounded: $any, children: $any) { return ReasonReact.wrapJsForReason(Avatar, {source: source, size: size, rounded: rounded}, children); };

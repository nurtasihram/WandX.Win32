#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.Security;
#endif

#include "WandX.Win32.String.h"

// from SDDL.h
#undef ConvertSidToStringSid
#undef ConvertStringSidToSid
#undef ConvertStringSecurityDescriptorToSecurityDescriptor
#undef ConvertSecurityDescriptorToStringSecurityDescriptor
#pragma endregion

// from AclApi.h
#undef SetEntriesInAcl
#undef GetExplicitEntriesFromAcl
#undef GetEffectiveRightsFromAcl
#undef GetAuditedPermissionsFromAcl
#undef GetNamedSecurityInfo
#undef SetNamedSecurityInfo
#undef GetInheritanceSource
#undef TreeResetNamedSecurityInfo
#undef TreeSetNamedSecurityInfo
#undef BuildSecurityDescriptor
#undef LookupSecurityDescriptorParts
#undef BuildExplicitAccessWithName
#undef BuildTrusteeWithName
#undef BuildTrusteeWithSid
#undef BuildTrusteeWithObjectsAndSid
#undef BuildTrusteeWithObjectsAndName
#undef GetTrusteeName
#undef GetTrusteeType
#undef GetTrusteeForm

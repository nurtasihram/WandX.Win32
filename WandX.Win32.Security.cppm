module;

#include <Windows.h>
#include <AclApi.h>
#include <SDDL.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Security.h"

export module WandX.Win32.Security;

import WandX;
import WandX.Win32;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Security");

export namespace WandX {
namespace Native {

#pragma region SDDL.h
wapi_ret_WAO(ConvertSidToStringSid, true);
wapi_ret_WAO(ConvertStringSidToSid, true);
wapi_ret_WAO(ConvertStringSecurityDescriptorToSecurityDescriptor, true);
wapi_ret_WAO(ConvertSecurityDescriptorToStringSecurityDescriptor, true);
#pragma endregion

#pragma region SecurityBaseAPI.h
wapi_ret(AccessCheck, true);
wapi_ret_WAO(AccessCheckAndAuditAlarm, true); // AccessCheckAndAuditAlarmA from WinBase.h
wapi_ret(AccessCheckByType, true);
wapi_ret(AccessCheckByTypeResultList, true);
wapi_ret_WAO(AccessCheckByTypeAndAuditAlarm, true); // AccessCheckByTypeAndAuditAlarmA from WinBase.h
wapi_ret_WAO(AccessCheckByTypeResultListAndAuditAlarm, true); // AccessCheckByTypeResultListAndAuditAlarmA from WinBase.h
wapi_ret_WAO(AccessCheckByTypeResultListAndAuditAlarmByHandle, true); // AccessCheckByTypeResultListAndAuditAlarmByHandleA from WinBase.h
wapi_ret(AddAccessAllowedAce, true);
wapi_ret(AddAccessAllowedAceEx, true);
wapi_ret(AddAccessAllowedObjectAce, true);
wapi_ret(AddAccessDeniedAce, true);
wapi_ret(AddAccessDeniedAceEx, true);
wapi_ret(AddAccessDeniedObjectAce, true);
wapi_ret(AddAce, true);
wapi_ret(AddAuditAccessAce, true);
wapi_ret(AddAuditAccessAceEx, true);
wapi_ret(AddAuditAccessObjectAce, true);
wapi_ret(AddMandatoryAce, true);
wapi_ret(AddResourceAttributeAce, true);
wapi_ret(AddScopedPolicyIDAce, true);
wapi_ret(AdjustTokenGroups, true);
wapi_ret(AdjustTokenPrivileges, true);
wapi_ret(AllocateAndInitializeSid, true);
wapi_ret(AllocateLocallyUniqueId, true);
wapi_ret(AreAllAccessesGranted, true);
wapi_ret(AreAnyAccessesGranted, direct);
wapi_ret(CheckTokenMembership, true);
wapi_ret(CheckTokenCapability, true);
wapi_ret(GetAppContainerAce, true);
wapi_ret(CheckTokenMembershipEx, true);
wapi_ret(ConvertToAutoInheritPrivateObjectSecurity, true);
wapi_ret(CopySid, true);
wapi_ret(CreatePrivateObjectSecurity, true);
wapi_ret(CreatePrivateObjectSecurityEx, true);
wapi_ret(CreatePrivateObjectSecurityWithMultipleInheritance, true);
wapi_ret(CreateRestrictedToken, true);
wapi_ret(CreateWellKnownSid, true);
wapi_ret(EqualDomainSid, true);
wapi_ret(DeleteAce, true);
wapi_ret(DestroyPrivateObjectSecurity, true);
wapi_ret(DuplicateToken, true);
wapi_ret(DuplicateTokenEx, true);
wapi_ret(EqualPrefixSid, direct);
wapi_ret(EqualSid, direct);
wapi_ret(FindFirstFreeAce, true);
wapi_ret(GetAce, true);
wapi_ret(GetAclInformation, true);
wapi_ret_WAO(GetFileSecurity, true); // GetFileSecurityA from WinBase.h
wapi_ret(GetKernelObjectSecurity, true);
wapi_ret(GetPrivateObjectSecurity, true);
wapi_ret(GetSecurityDescriptorControl, true);
wapi_ret(GetSecurityDescriptorDacl, true);
wapi_ret(GetSecurityDescriptorGroup, true);
wapi_ret(GetSecurityDescriptorOwner, true);
wapi_ret(GetSecurityDescriptorSacl, true);
wapi_ret(GetTokenInformation, true);
wapi_ret(GetWindowsAccountDomainSid, true);
wapi_ret(ImpersonateAnonymousToken, true);
wapi_ret(ImpersonateLoggedOnUser, true);
wapi_ret(ImpersonateSelf, true);
wapi_ret(InitializeAcl, true);
wapi_ret(InitializeSecurityDescriptor, true);
wapi_ret(InitializeSid, true);
wapi_ret(IsTokenRestricted, direct);
wapi_ret(IsValidAcl, direct);
wapi_ret(IsValidSecurityDescriptor, direct);
wapi_ret(IsValidSid, direct);
wapi_ret(IsWellKnownSid, direct);
wapi_ret(MakeAbsoluteSD, true);
wapi_ret(MakeSelfRelativeSD, true);
wapi_ret_WAO(ObjectCloseAuditAlarm, true); // ObjectCloseAuditAlarmA from WinBase.h
wapi_ret_WAO(ObjectDeleteAuditAlarm, true); // ObjectDeleteAuditAlarmA from WinBase.h
wapi_ret_WAO(ObjectOpenAuditAlarm, true); // ObjectOpenAuditAlarmA from WinBase.h
wapi_ret_WAO(ObjectPrivilegeAuditAlarm, true); // ObjectPrivilegeAuditAlarmA from WinBase.h
wapi_ret(PrivilegeCheck, true);
wapi_ret_WAO(PrivilegedServiceAuditAlarm, true); // PrivilegedServiceAuditAlarmA from WinBase.h
wapi_ret(RevertToSelf, true);
wapi_ret(SetAclInformation, true);
wapi_ret_WAO(SetFileSecurity, true); // SetFileSecurityA from WinBase.h
wapi_ret(SetKernelObjectSecurity, true);
wapi_ret(SetPrivateObjectSecurity, true);
wapi_ret(SetPrivateObjectSecurityEx, true);
wapi_ret(SetSecurityDescriptorControl, true);
wapi_ret(SetSecurityDescriptorDacl, true);
wapi_ret(SetSecurityDescriptorGroup, true);
wapi_ret(SetSecurityDescriptorOwner, true);
wapi_ret(SetSecurityDescriptorSacl, true);
wapi_ret(SetTokenInformation, true);
wapi_ret(SetCachedSigningLevel, true);
wapi_ret(GetCachedSigningLevel, true);
wapi_ret(DeriveCapabilitySidsFromName, true);
wapi_ret(GetLengthSid, direct);
wapi_ret(GetSecurityDescriptorLength, direct);
wapi_ret(GetSecurityDescriptorRMControl, true);
wapi_ret(GetSidLengthRequired, direct);
wapi_ret(SetSecurityDescriptorRMControl, true);
wapi_ret(CveEventWrite, true);
// GetSidSubAuthority
inline PDWORD GetSidSubAuthority(PSID pSid, DWORD nSubAuthority)
ret_safe_to(auto h = ::GetSidSubAuthority(pSid, nSubAuthority), h);
// GetSidIdentifierAuthority
inline PSID_IDENTIFIER_AUTHORITY GetSidIdentifierAuthority(PSID pSid)
ret_safe_to(auto h = ::GetSidIdentifierAuthority(pSid), h);
// GetSidSubAuthorityCount
inline PUCHAR GetSidSubAuthorityCount(PSID pSid)
ret_safe_to(auto h = ::GetSidSubAuthorityCount(pSid), h);
wapi_ret(FreeSid, true);
wapi_ret(MapGenericMask, direct);
wapi_ret(QuerySecurityAccessMask, direct);
wapi_ret(SetSecurityAccessMask, direct);
#pragma endregion

#pragma region AclApi.h
wapi_ret_WAO(SetEntriesInAcl, true);
wapi_ret_WAO(GetExplicitEntriesFromAcl, true);
wapi_ret_WAO(GetEffectiveRightsFromAcl, true);
wapi_ret_WAO(GetAuditedPermissionsFromAcl, true);
wapi_ret_WAO(GetNamedSecurityInfo, true);
wapi_ret(GetSecurityInfo, true);
wapi_ret_WAO(SetNamedSecurityInfo, true);
wapi_ret(SetSecurityInfo, true);
wapi_ret_WAO(GetInheritanceSource, true);
wapi_ret(FreeInheritedFromArray, true);
wapi_ret_WAO(TreeResetNamedSecurityInfo, true);
wapi_ret_WAO(TreeSetNamedSecurityInfo, true);
wapi_ret_WAO(BuildSecurityDescriptor, true);
wapi_ret_WAO(LookupSecurityDescriptorParts, true);
wapi_ret_WAO(BuildExplicitAccessWithName, direct);
wapi_ret_WAO(BuildTrusteeWithName, direct);
wapi_ret_WAO(BuildTrusteeWithSid, direct);
wapi_ret_WAO(BuildTrusteeWithObjectsAndSid, direct);
wapi_ret_WAO(BuildTrusteeWithObjectsAndName, direct);
wapi_ret_WAO(GetTrusteeName, direct);
wapi_ret_WAO(GetTrusteeType, direct);
wapi_ret_WAO(GetTrusteeForm, direct);
#pragma endregion

}

// #include "WandX.Win32.Security.h"

}

/*******************************************************************************
* Copyright (C) 2004 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the 'License');
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing,
* software distributed under the License is distributed on an 'AS IS' BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions
* and limitations under the License.
* 
*******************************************************************************/

/* 
//  Purpose:
//     Intel(R) Integrated Performance Primitives. Cryptographic Primitives (ippcp)
//     Prime Number Primitives.
// 
//  Contents:
//        ippsPrimeGet_BN()
//
*/

#include "owncp.h"
#include "pcpprimeg.h"

/*F*
// Name: ippsPrimeGet_BN
//
// Purpose: Extracts probable prime and store into BN.
//
// Returns:                   Reason:
//    ippStsNullPtrErr           NULL == pCtx
//                               NULL == pPrime
//    ippStsContextMatchErr      illegal pCtx->idCtx
//                               illegal pPrime->idCtx
//    ippStsOutOfRangeErr        BN_ROOM(pPrime) < BITS_BNU_CHUNK(PRIME_MAXBITSIZE(pCtx))
//    ippStsNoErr                no error
//
// Parameters:
//    pPrime   pointer to the BN
//    pCtx     pointer to the context
//
*F*/
IPPFUN(IppStatus, ippsPrimeGet_BN, (IppsBigNumState* pPrime, const IppsPrimeState* pCtx))
{
   IPP_BAD_PTR2_RET(pCtx, pPrime);

   IPP_BADARG_RET(!BN_VALID_ID(pPrime), ippStsContextMatchErr);
   IPP_BADARG_RET(!PRIME_VALID_ID(pCtx), ippStsContextMatchErr);

   {
      BNU_CHUNK_T* pValue = PRIME_NUMBER(pCtx);
      cpSize ns = BITS_BNU_CHUNK(PRIME_MAXBITSIZE(pCtx));
      FIX_BNU(pValue, ns);

      IPP_BADARG_RET(BN_ROOM(pPrime) < ns, ippStsOutOfRangeErr);

      COPY_BNU(BN_NUMBER(pPrime), pValue, ns);
      BN_SIZE(pPrime) = ns;
      BN_SIGN(pPrime) = ippBigNumPOS;

      return ippStsNoErr;
   }
}

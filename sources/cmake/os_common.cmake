#===============================================================================
# Copyright (C) 2023 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the 'License');
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an 'AS IS' BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions
# and limitations under the License.
# 
#===============================================================================

#
# Intel® Integrated Performance Primitives Cryptography (Intel® IPP Cryptography)
#

# The ability to build custom IPP Crypto library - enable specific CPU features at compile time
if((NOT MERGED_BLD) AND (NOT "${IPPCP_CUSTOM_BUILD}" STREQUAL ""))
  set(LIBRARY_DEFINES "${LIBRARY_DEFINES} -DIPPCP_CUSTOM_BUILD")
  foreach(feature ${IPPCP_CUSTOM_BUILD})
    set(LIBRARY_DEFINES "${LIBRARY_DEFINES} -D${feature}")
  endforeach(feature ${IPPCP_CUSTOM_BUILD})
endif()

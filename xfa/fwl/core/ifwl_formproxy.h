// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FWL_CORE_IFWL_FORMPROXY_H_
#define XFA_FWL_CORE_IFWL_FORMPROXY_H_

#include "xfa/fwl/core/ifwl_form.h"

class CFWL_WidgetImpProperties;
class CFWL_FormProxyImpDelegate;

class IFWL_FormProxy : public IFWL_Form {
 public:
  IFWL_FormProxy(const CFWL_WidgetImpProperties& properties,
                 IFWL_Widget* pOuter);
  ~IFWL_FormProxy() override;

  // IFWL_Widget
  FWL_Type GetClassID() const override;
  FX_BOOL IsInstance(const CFX_WideStringC& wsClass) const override;
  FWL_Error Initialize() override;
  void Finalize() override;
  FWL_Error Update() override;
  FWL_Error DrawWidget(CFX_Graphics* pGraphics,
                       const CFX_Matrix* pMatrix = nullptr) override;

 protected:
  friend class CFWL_FormProxyImpDelegate;
};

class CFWL_FormProxyImpDelegate : public CFWL_WidgetImpDelegate {
 public:
  CFWL_FormProxyImpDelegate(IFWL_FormProxy* pOwner);
  void OnProcessMessage(CFWL_Message* pMessage) override;

 protected:
  IFWL_FormProxy* m_pOwner;
};

#endif  // XFA_FWL_CORE_IFWL_FORMPROXY_H_
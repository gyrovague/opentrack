/* Homepage         http://facetracknoir.sourceforge.net/home/default.htm        *
 *                                                                               *
 * ISC License (ISC)                                                             *
 *                                                                               *
 * Copyright (c) 2015, Wim Vriend                                                *
 *                                                                               *
 * Permission to use, copy, modify, and/or distribute this software for any      *
 * purpose with or without fee is hereby granted, provided that the above        *
 * copyright notice and this permission notice appear in all copies.             *
 */
#include "ftnoir_protocol_fsuipc.h"
#include "opentrack/plugin-api.hpp"

FSUIPCControls::FSUIPCControls()
{
    ui.setupUi( this );
    connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(doOK()));
    connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(doCancel()));
    connect(ui.btnFindDLL, SIGNAL(clicked()), this, SLOT(getLocationOfDLL()));

    tie_setting(s.LocationOfDLL, ui.txtLocationOfDLL);
}

void FSUIPCControls::doOK() {
    s.b->save();
    this->close();
}

void FSUIPCControls::doCancel() {
    s.b->reload();
    close();
}

void FSUIPCControls::getLocationOfDLL()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Locate file"),
                                                    ui.txtLocationOfDLL->text(),
                                                    tr("FSUIPC DLL file (FSUIPC*.dll);;All Files (*)"));
    if (!fileName.isEmpty()) {
        s.LocationOfDLL = fileName;
    }
}


/* Copyright (c) 2014-2015, Stanislaw Halik <sthalik@misaki.pl>

 * Permission to use, copy, modify, and/or distribute this
 * software for any purpose with or without fee is hereby granted,
 * provided that the above copyright notice and this permission
 * notice appear in all copies.
 */

#include "curve-config.h"
#include "opentrack/main-settings.hpp"
MapWidget::MapWidget(Mappings& m, main_settings& s) :
    m(m)
{
    ui.setupUi( this );

    // rest of mapping settings taken care of by options::value<t>
    m.load_mappings();

    {
        struct {
            QFunctionConfigurator* qfc;
            Axis axis;
            QCheckBox* checkbox;
            bool altp;
        } qfcs[] =
        {
            { ui.rxconfig, Yaw,   nullptr, false },
            { ui.ryconfig, Pitch, nullptr, false },
            { ui.rzconfig, Roll,  nullptr, false },
            { ui.txconfig, TX,    nullptr, false },
            { ui.tyconfig, TY,    nullptr, false },
            { ui.tzconfig, TZ,    nullptr, false },

            { ui.rxconfig_alt, Yaw,   ui.rx_altp, true },
            { ui.ryconfig_alt, Pitch, ui.ry_altp, true },
            { ui.rzconfig_alt, Roll,  ui.rz_altp, true },
            { ui.txconfig_alt, TX,    ui.tx_altp, true },
            { ui.tyconfig_alt, TY,    ui.ty_altp, true },
            { ui.tzconfig_alt, TZ,    ui.tz_altp, true },
            { nullptr, Yaw, nullptr, false }
        };

        for (int i = 0; qfcs[i].qfc; i++)
        {
            const bool altp = qfcs[i].altp;
            Mapping& axis = m(qfcs[i].axis);
            Map* conf = altp ? &axis.curveAlt : &axis.curve;
            const auto& name = qfcs[i].altp ? axis.name2 : axis.name1;
            if (altp)
            {
                QFunctionConfigurator& qfc = *qfcs[i].qfc;
                connect(qfcs[i].checkbox, &QCheckBox::toggled,
                        [&](bool f) -> void {qfc.setEnabled(f); qfc.force_redraw();});
                qfc.setEnabled(qfcs[i].checkbox->isChecked());
                qfc.force_redraw();
            }
            
            if (qfcs[i].axis >= 3)
                qfcs[i].qfc->set_snap(2, 5);
            else
                qfcs[i].qfc->set_snap(1, 5);
            
            qfcs[i].qfc->setConfig(conf, name);
        }
    }

    setFont(qApp->font());
    connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(doOK()));
    connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(doCancel()));

    tie_setting(s.a_x.altp, ui.tx_altp);
    tie_setting(s.a_y.altp, ui.ty_altp);
    tie_setting(s.a_z.altp, ui.tz_altp);
    tie_setting(s.a_yaw.altp, ui.rx_altp);
    tie_setting(s.a_pitch.altp, ui.ry_altp);
    tie_setting(s.a_roll.altp, ui.rz_altp);
}

void MapWidget::doOK() {
    m.save_mappings();
    this->close();
}

void MapWidget::doCancel() {
    m.invalidate_unsaved();
    this->close();
}

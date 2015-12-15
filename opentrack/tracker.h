/* Copyright (c) 2014-2015, Stanislaw Halik <sthalik@misaki.pl>

 * Permission to use, copy, modify, and/or distribute this
 * software for any purpose with or without fee is hereby granted,
 * provided that the above copyright notice and this permission
 * notice appear in all copies.
 */

#pragma once

#include <vector>

#include "opentrack-compat/timer.hpp"
#include "plugin-support.hpp"
#include "mappings.hpp"
#include "simple-mat.hpp"
#include "selected-libraries.hpp"

#include "spline-widget/functionconfig.h"
#include "main-settings.hpp"
#include "opentrack-compat/options.hpp"

#include <QMutex>
#include <QThread>

class Pose {
private:
    static constexpr double pi = 3.141592653;
    static constexpr double d2r = pi/180.0;
    static constexpr double r2d = 180./pi;

    double axes[6];
public:
    Pose() : axes {0,0,0, 0,0,0} {}

    inline operator double*() { return axes; }
    inline operator const double*() const { return axes; }

    inline double& operator()(int i) { return axes[i]; }
    inline double operator()(int i) const { return axes[i]; }
};

#ifdef BUILD_api
#   include "opentrack-compat/export.hpp"
#else
#   include "opentrack-compat/import.hpp"
#endif

class OPENTRACK_EXPORT Tracker : private QThread {
    Q_OBJECT
private:
    QMutex mtx;
    main_settings& s;
    Mappings& m;

    Timer t;
    Pose output_pose, raw_6dof, last_mapped, last_raw;

    double newpose[6];
    volatile bool centerp;
    volatile bool enabledp;
    volatile bool zero_;
    volatile bool should_quit;
    SelectedLibraries const& libs;

    using rmat = dmat<3, 3>;
    
    dmat<3, 3> r_b;
    double t_b[3];

    double map(double pos, Mapping& axis);
    void logic();

    void t_compensate(const dmat<3, 3>& rmat, const double* ypr, double* output, bool rz);
    void run() override;
    
public:
    Tracker(main_settings& s, Mappings& m, SelectedLibraries& libs);
    ~Tracker();

    void get_raw_and_mapped_poses(double* mapped, double* raw) const;
    void start() { QThread::start(); }
    void toggle_enabled() { qDebug() << "toggle enabled"; enabledp = !enabledp; }
    void center() { qDebug() << "toggle center"; centerp = !centerp; }
    void zero() { qDebug() << "toggle zero"; zero_ = !zero_; }
};

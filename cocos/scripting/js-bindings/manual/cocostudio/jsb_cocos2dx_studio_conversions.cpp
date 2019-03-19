/*
 * Created by Huabin LING on 21/1/15.
 * Copyright (c) 2015 Chukong Technologies Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"

#include "jsb_cocos2dx_studio_conversions.h"
#include "cocostudio/CocoStudio.h"

bool animationInfo_to_seval(const cocostudio::timeline::AnimationInfo& v, se::Value* ret)
{
    assert(ret != nullptr);

    se::HandleObject obj(se::Object::createPlainObject());
    obj->setProperty("name", se::Value(v.name));
    obj->setProperty("startIndex", se::Value(v.startIndex));
    obj->setProperty("endIndex", se::Value(v.endIndex));
    ret->setObject(obj);

    return true;
}

bool seval_to_animationInfo(const se::Value& v, cocostudio::timeline::AnimationInfo* ret)
{
    static cocostudio::timeline::AnimationInfo ZERO;

    assert(ret != nullptr);
    assert(v.isObject());
    se::Value tmp;
    se::Object* obj = v.toObject();
    bool ok = false;

    ok = obj->getProperty("name", &tmp);
    SE_PRECONDITION3(ok && tmp.isString(), false, *ret = ZERO);
    ret->name = tmp.toString();

    ok = obj->getProperty("startIndex", &tmp);
    SE_PRECONDITION3(ok && tmp.isNumber(), false, *ret = ZERO);
    ret->startIndex = tmp.toInt32();

    ok = obj->getProperty("endIndex", &tmp);
    SE_PRECONDITION3(ok && tmp.isNumber(), false, *ret = ZERO);
    ret->endIndex = tmp.toInt32();

    return true;
}

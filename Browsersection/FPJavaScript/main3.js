class MayBe{
    static of(value){
        return new MayBe(value);
    }
    constructor (value){
        this._value=value;
    }
    map(fn){
        return this.isNothing() ? MapBe.of(null):MapBe.of(fn(this._value));
    }
    isNothing () {
        return this._value ==null || this._value == undefined;
    }
}